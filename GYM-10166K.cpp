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

void solve(){
  int n; cin >> n;
  
  // the algorithm seems to inverse the connections
  // and start bfs from 0
  
  vector<vector<int>> adj(n);
  string s;
  forn(i, n){
  	cin >> s;
  	forn(j, n) if (s[j] == '1') adj[i].pb(j);
  }
  
  // forn(i, n){
  //   cout << i << " ->  ";
  //   for(auto j: adj[i]) cout << j << " "; cout << endl;
  // }
  
  
  
  queue<int> q;
  vector<int> check(n, 0);
  vector<ii> order_visit;
  vector<int> p(n);
  iota(all(p), 0);
  q.push(0);
  
  int cnt = 1;
  while(!q.empty()){
  	int u = q.front(); q.pop();
  	if (check[u]) continue;
    // cout << u << "\n";
  	check[u] = cnt++;
    order_visit.pb({check[u], u})
  	for(int v: adj[u]){
  		q.push(v);
  		p[v] = u;
  	}
  }
  
  // for(auto i: p) cout << i << " "; cout << endl;
  // for(auto i: check) cout << i << " "; cout << endl;
  if (cnt <= n) {
    cout << "impossible" << endl;
    return;
  }
  
  // In the next line of code, due to the order by bfs
  // we can print the complete way
  
  sort(order_visit.rbegin(), order_visit.rend());
  
  for(auto i: order_visit) cout << i.ss << " " ; cout << endl;
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