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
  int s;
  cin >> s;
  // Za Warudo Toki wo Tomare Wrryyyyyy!!!
  for (int a = 0; a * a <= s; a++) {
    for (int b = 0; b * b <= s; b++) {
      if (a == 0 && b == 0) continue;
      if (a * a + b * b == s) {
        // Square vertices
        cout << 0 << " " << 0 << "\n";
        cout << a << " " << b << "\n";
        cout << a - b << " " << b + a << "\n";
        cout << -b << " " << a << "\n";
        return;
      }
    }
  }

  cout << "Impossible\n";
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