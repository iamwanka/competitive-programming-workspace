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

ll binary_exp(ll a, ll b) {
  ll ans = 1;
  ll pow = 1;

  while (b) {
    if (b & 1) ans *= pow;
    pow *= a;
    b <<= 1;
  }

  return ans;
}

void solve() {
  ll a, b; cin >> a >> b;
  int limitA = log(1e18) / log(a);
  int limitB = log(1e18) / log(b);
  // cout << a << " " << b << endl;
  
  auto f = [&] (ll x) {
    return 1.0 * x / log(x);
  };

  ll low = 0.0, high = 2e18;
  long double c = log(a) / b;
  forn(i, 100) {
    ll mid = (low + high) / 2;
    
    
    if (log(mid) / mid > c) low = mid;
    else high = mid;
  }
  // cout << low << " " << high << endl;
  long double k = log(low) / low;
  if (fabs(k - c) < 1e-6) cout << low << endl;
  else{
    long double j = log(high) / high;
    if (fabs(j- c) < 1e-6) cout << high << endl;
    else cout << 0 << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}