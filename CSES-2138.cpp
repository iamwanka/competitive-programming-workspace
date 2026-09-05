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
const int MAXN = 5e4 + 5;

bitset<MAXN> mask[MAXN];
vector<int> adj[MAXN];
bitset<MAXN> check;

void dfs (int u) {
  if (check[u]) return;
  check[u] = 1;
  mask[u][u] = 1;

  for (int &i : adj[u]) {
    dfs(i); // First visit the whole graph
    // Then, join the children's mask
    mask[u] |= mask[i];
  }
}

void solve() {
  int n, m; cin >> n >> m;

  while (m--) {
    int x, y; cin >> x >> y;
    adj[x].pb(y);
  }

  // Hints that has to be take in mind
  // - The graph can have many components
  // - Za Hando Over Heaven


  // Utilization of:
  // - The checker that check components
  // - DFS to realize a sort of topological sort
  // - Bitset Array to check
  forabe(i, 1, n) {
    if (!check[i]) dfs(i);
  }

  forab(i, 0, n) {
    if (i == 0) cout << mask[i + 1].count();
    else cout << " " << mask[i + 1].count();
  }
  cout << endl;
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