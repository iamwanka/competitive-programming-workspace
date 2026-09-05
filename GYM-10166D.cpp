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

const ll INF = 1e17;
vector<vector<pair<int, ll>>> adj;
// In this function, is returned two vectors, distance and parents
void dijkstra(int s, vector<ll> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    set<pair<ll, int>> q;
    q.insert({0LL, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

vector<int> check;
vector<int> warn;
vector<int> father_of;
bool bfs (){
    queue<int> q;
    q.push(0);
    check[0] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if (u == 1) return true;
        for (auto i: adj[u]){
            int to = i.first;
            if (check[to] || warn[u] == to) continue;
            check[to] = 1;
            // cout << u << " "; 
            father_of[to] = u;
            q.push(to);
        }
    }
    return false;
}



void solve(){
  int n, m; cin >> n >> m;
  adj.resize(n);
  check.resize(n, false);
  father_of.resize(n);
  iota(all(father_of), 0);
  
  while(m--){
  	int u, v;
    ll d;
  	cin >> u >> v >> d;
  	adj[u].pb({v, d});
    adj[v].pb({u, d});
  }
  vector<int> p;
  vector<ll> d;
    dijkstra(1, d, p);
    
    warn = p;
    
    if (bfs()){
        vector<int> v = {1};
        int u = 1;
        while(father_of[u] != u){
            u = father_of[u];
            v.pb(u);
        }
        reverse(all(v));
        cout << v.size() << " ";
        for(auto i: v) cout << i << " ";
    }
   else cout << "impossible" << endl;
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