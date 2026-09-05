//g++ -std=c++17 -Wall -Wextra -O2 -DLOCAL main.cpp -o main && ./main < in.txt
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
using namespace std;

void _print() { cerr << "]" << endl; }
template<typename T, typename... V>
void _print(T t, V... v) { cerr << t; if (sizeof...(v)) cerr << ", "; _print(v...); }

#define LOCAL
#ifdef LOCAL
  #define dbg(x...) cerr << "[" << #x << "]: ["; _print(x)
#else
  #define dbg(x...)
  #define endl '\n'
#endif

#define pb push_back
#define ff first
#define ss second
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define forne(i, n) for (int i = 0; i <= n; ++i)
#define rforn(i, n) for (int i = n-1; i >= 0; --i)
#define forab(i, a, b) for (int i = a; i < b; ++i)
#define forabe(i, a, b) for (int i = a; i <= b; ++i)
#define form(i, n, m, x) for (int i = n; i < m; i += x)
#define rform(i, n, m, x) for (int i = n; i >= m; i -= x)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;



void solve() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    long long sumA = accumulate(a.begin(), a.end(), 0LL);
    if (sumA < s) {
        cout << -1 << '\n';
        return;
    }

    vector<int> direct = a;
    vector<vector<int>> children(n);

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    // Sort by increasing size
    sort(order.begin(), order.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    long long remaining = sumA;

    // Multiset of possible parents (bigger bags)
    multiset<pair<int,int>> available;

    for (int i = n - 1; i >= 0; --i) {
        available.insert({a[order[i]], order[i]});
    }

    for (int idx : order) {
        available.erase(available.find({a[idx], idx}));

        if (remaining - a[idx] >= s && !available.empty()) {
            // Nest this bag
            auto parent = *available.begin();
            children[parent.second].push_back(idx);
            direct[idx] = 0;
            remaining -= a[idx];
        }
    }

    if (remaining != s) {
        cout << -1 << '\n';
        return;
    }

    // Output
    for (int i = 0; i < n; i++) {
        cout << direct[i] << " " << children[i].size();
        for (int x : children[i]) cout << " " << x + 1;
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
