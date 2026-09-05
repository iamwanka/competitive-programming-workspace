//g++ -std=c++17 -Wall -Wextra -O2 -DLOCAL main.cpp -o main && ./main < in.txt
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
  ll w, h, d; cin >> w >> h >> d;
  ll n; cin >> n;

  // Find the the prime divisors
  vector<int> vw, vh;
  for (ll i = 1; i <= sqrt(w); i++) {
    if (w % i == 0) {
      vw.pb(i);
      ll k = w / i;
      if (k != i) vw.pb(k);
    }
  }
  
  for (ll i = 1; i <= sqrt(h); i++) {
    if (h % i == 0) {
      vh.pb(i);
      ll k = h / i;
      if (k != i) vh.pb(k);
    }
  }
  
  forn(i, sz(vw)){
    forn(j, sz(vh)){
      ll partial_mul = vw[i] * vh[j];
      ll vd = n / partial_mul;
        cout << vw[i] - 1 << " " << vh[j] - 1 << " " << vd - 1<< endl;
      if (partial_mul * vd == n && h % vd == 0)
      {
        cout << vw[i] - 1 << " " << vh[j] - 1 << " " << vd - 1 << endl;
        return;
      }
    }
  }
  cout << -1 << endl;
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