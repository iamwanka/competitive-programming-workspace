//g++ -std=c++17 -Wall -Wextra -O2 -DLOCAL main.cpp -o main && ./main < in.txt
#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
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
  // Aproach: In every position find the the nearest number that is more or equal
  // that the value 
  
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  	
  // What we need?
  // - A set pair-value that organize the values, the goal is to make binary search
  //   with a complexity O(N*long(N))
  multiset<ii> st;
  forn(i, n) st.insert(make_pair(a[i], i));
  
  vector<int> next_idx(n, 1);
  int ans = 1;
  forn(i, n){
  	st.erase(make_pair(a[i], i));
  	set<ii>::iterator tmp = st.lower_bound(make_pair(a[i], -1));
    if (tmp == st.end()) continue;
  	int idx = tmp -> second;
  	next_idx[idx] = max(next_idx[idx], next_idx[i] + 1);
    ans = max(ans, next_idx[idx]);
  }
  
  // for(auto &i: next_idx) cout << i << " "; cout << endl;
  cout << ans << endl;
}

void solve1(){
  int n; cin >> n;
  
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  
  vi dp(n, 1);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++){
      if (a[j] < a[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  
  int ans = 0;
  for(int i = 0; i < n; i++) ans = max(ans, dp[i]);
  cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    while(t--){
    	solve1();
    }
    return 0;
}	