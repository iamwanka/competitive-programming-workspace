#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
#endif // ONLINE_JUDGE

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rnk(x, y) upper_bound(all((x)), (y)) - (x).begin()

typedef long double ld;
typedef long long ll;
typedef __int128 LL;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

static int rnd(int lo, int hi) {
    return uniform_int_distribution<int>(lo, hi)(rng);
}

const ll oo = 1e18;

const ll MAX = 7e4 + 5;
const ll mod = 1e9 + 7;

void solve() {
    ll n, k, s = 0;
    cin >> n >> k;
    vector<ll> v(n), pre(MAX, -1), in(n, -1);
    for (ll &x: v)
        cin >> x, s += x;
    int p = max_element(all(v)) - v.begin();
    if (v[p] > k || s < k) {
        cout << "-1\n";
        return;
    }
    k -= v[p];
    bitset<MAX> dp = 1;
    for (ll &x: v) {
        if (&x - &v[0] == p)continue;
        auto nxt = dp | (dp << x);
        dp ^= nxt;
        int where = dp._Find_first();
        while (where < MAX) {
            pre[where] = &x - &v[0];
            dp[where] = 0;
            where = dp._Find_first();
        }
        dp = nxt;
    }
    if (!dp[k]) {
        cout << "-1\n";
    } else {
        int pos = pre[k];
        while (pos != -1) {
            in[pos] = -2;
            k -= v[pos];
            pos = pre[k];
        }
        vector<int> ind;
        for (int i = 0; i < n; i++)
            if (in[i] == -1)
                ind.emplace_back(i);
        sort(all(ind), [&](int i, int j) { return v[i] < v[j]; });
        for (int i = 1; i < ind.size(); i++)
            in[ind[i]] = ind[i - 1];
        for (int i = 0; i < n; i++) {
            if (in[i] < 0)
                cout << v[i] << " 0\n";
            else
                cout << v[i] - v[in[i]] << " 1 " << in[i] + 1 << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;

    while (tc--)
        solve();
}