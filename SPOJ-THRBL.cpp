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


struct SparseTable {
  int n, K;
  vector<vector<int>> st;
  
  // Function to construct 
  SparseTable(const vector<int> &a) {
    n = sz(a);
    K = int(log2(n)) + 1;
    st.assign(n + 1, vector<int>(K));
    forn (i, n) st[i][0] = a[i];
    forn (j, K - 1)
      for (int i = 0; i + (1 << (j + 1)) <= n; ++i)
        st[i][j + 1] = oper(st[i][j], st[i + (1 << j)][j]);
  }

  int oper(int a, int b) { return max(a, b); }

  int query(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return oper(st[l][k], st[r - (1 << k) + 1][k]);
  }
};


void solve(){
  int n, m; cin >> n >> m;
  // The idea of use sparse table to answer queries in O(1)
  vector<int> v(n);
  forn(i, n) cin >> v[i];
  
  
  SparseTable st(v);
  
    
  // Answering the queries in O(1)
  long long ans = 0;
  while(m--){
  	int l, r;
  	cin >> l >> r;
  	--r, --l;
    
    if (l > r) swap(r, l);
    if (l == r) {ans++; continue;}
    
    int maximun = st.query(l, r - 1);   
    bool c = (v[l] >= maximun);
    ans += c;
  }
  
  cout << ans << endl;
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