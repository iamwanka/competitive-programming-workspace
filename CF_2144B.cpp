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
  vi a(n + 1); 
  int pos = 0; 
  int cnt = 0;
  int remain = 0; 
  forab (i, 1, n + 1){
    cin >> a[i];
    if (a[i] == 0){
      cnt++;
      pos = i;
    }
    remain += i - a[i];
  }
  
  if (cnt == 1) a[pos] = remain;
  
  int l = 1;
  while(l <= n && a[l] == l){
    l++;
  }
  
  int r = n;
  while(r >= 1 && a[r] == r){
    r--;
  }
  
  if (l > r) {
    cout << 0 << '\n';
  }
  else cout << r - l + 1 << "\n";
  
  
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