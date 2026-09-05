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

struct cmp{
	bool operator() (const ii &a, const ii &b) const {
		if (a.first == b.first) return a.second < b.second;
		return a.first < b.first;
	}
};

const int N = 200000; 
int n, m;
int tree[4*N];
int h[N];

void build(int node, int l, int r){
  if (l == r) {
    tree[node] = h[l];
    return;
  };
  
  int mid = (l + r) / 2;
  build(2*node, l, mid);
  build(2*node + 1, mid + 1, r);
  
  tree[node] = max(tree[2*node], tree[2*node + 1]);
}

int query(int node, int l, int r, int x){
  if (tree[node] < x) return -1;
  if (l == r) return l;
  
  int mid = (l + r) / 2;
  
  if (tree[2*node] >= x) 
    return query(2*node, l, mid, x);
  else 
    return query(2*node + 1, mid + 1, r, x);
}

void update(int node, int l, int r, int idx, int val){
  if (l == r) {
    tree[node] -= val;
    return;
  }
  
  int mid = (l + r) / 2;
  
  if (idx <= mid) 
    update(2*node, l, mid, idx, val);
  else 
    update(2*node + 1, mid + 1, r, idx, val);
  
  // Recalcular el nodo actual
  tree[node] = max(tree[2*node] , tree[2*node + 1]);
}

void solve(){
  int n, m; cin >> n >> m;
  
  forn(i, n) cin >> h[i];
  
  build(1, 0, n - 1);
  // for(ii x: pq) cout << x.ff << " " << x.ss << endl;
  // cout << endl;
  // La idea es encontrar el primer hotel desde la izquierda
  // y llenarlo
  
  while(m--){
    int r; cin >> r;
    
    int idx = query(1, 0, n - 1, r);
    if (idx == -1) {
      cout << 0 << " ";
    }
    else {
      cout << idx + 1 << " ";
      update(1, 0, n - 1, idx, r);
    }
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