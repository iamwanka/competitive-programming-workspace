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
  int w, h; cin >> w >> h;
  vector<vector<char>> vs(w + 1, vector<char> (h + 1));
  
  for(int i = 1; i <= w; i++)
  	for(int j = 1; j <= h; j++) cin >> vs[i][j];
  
  // for(int i = 1; i <= w; i++) {
  //   for(int j = 1; j <= h; j++) cout << vs[i][j];
  //     cout << endl;
  // }

  
  vector<vector<int>> count_path(w + 1, vector<int>(h + 1, 0));
  count_path[1][1] = 1;
  
  const int MOD = 1000000007;
  for(int i = 1; i <= w; i++){
  	for(int j = 1; j <= h; j++) {
      if (i == 1 && j == 1) count_path[1][1] = 1;
      else if (vs[i][j] == '#') continue;
      else count_path[i][j] = (count_path[i - 1][j] + count_path[i][j - 1]) % MOD;
    }
  }
  
  // for(int i = 1; i <= w; i++){
  //   for(int j = 1; j <= h; j++) cout << count_path[i][j] << " ";
  //     cout << endl;
  // }

  cout << count_path[w][h] << endl;
	
  
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