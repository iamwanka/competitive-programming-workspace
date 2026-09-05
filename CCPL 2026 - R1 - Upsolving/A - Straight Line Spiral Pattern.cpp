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

int n;

bool inside(int x, int y) {
  return x >= 0 && x < n  && y >= 0 && y < n;
}

void solve(){
  cin >> n;
  vector<vector<char>> matrix(n, vector<char> (n, '*'));
  // The idea is to turn 90 degree to the right if i find an obstacle
  // otherwise keep forward
  
  int dx[4] = {-1, 0, +1, 0};
  int dy[4] = {	0, 1, 0, -1};
  
  int x = 1, y = 0;
  int dir = 1; // use to change direction (Right)
  
  // matrix[x][y] = '.';
  
  while(true){
    matrix[x][y] = '.';
    
    // cout << x << " " << y << endl;
  	int nx = x + dx[dir];
  	int ny = y + dy[dir];
    
    int nnx = nx + dx[dir];
    int nny = ny + dy[dir];
    
  	// Calculate a new direction
    
  	if (!inside(nnx, nny) 
        || (inside(nnx, nny) && matrix[nnx][nny] == '.')) {
  		// Correct my trajectory
      
      // Then, change the direction
  		dir = (dir + 1) % 4;
      
      nx = x + dx[dir];
      ny = y + dy[dir];
      
      nnx = nx + dx[dir];
      nny = ny + dy[dir];
      
      if (!inside(nx, ny) || !inside(nnx, nny) || matrix[nx][ny] == '.' || matrix[nnx][nny] == '.') break;
  	}
    // matrix[x][y] = '.';
  	x = nx, y = ny;  	
  }
  
  for(auto &i: matrix) {
    for (auto &j: i) cout << j;
      cout << endl;
  }
  
  // cout << endl;
  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    forn(i, t){
      if (i != 0) cout << endl;
    	solve();
    }
    return 0;
}