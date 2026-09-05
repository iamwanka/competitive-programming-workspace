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
  int n, m; cin >> n >> m;
  
  
  vector<vector<int>> mtx(n, vector<int> (m));
  forn(i, n)
  	forn(j, m) cin >> mtx[i][j];
  
  if (n == 1 && m == 1) {
  	cout << -1 << endl;
  	return;
  }
  
  rotate(mtx.begin(), mtx.begin() + 1, mtx.end());
  forn(i, n)
  	rotate(mtx[i].begin(), mtx[i].begin() + 1, mtx[i].end());
  
  forn(i, n){
  	forn(j, m)
  		cout << mtx[i][j] << " ";
  	
  	cout << endl;
  }
  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}