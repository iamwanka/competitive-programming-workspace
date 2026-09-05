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
  vector<ll> a(n), b(n);
  set<ll> s;
  
  // The set is used to identify the unique elements
  
  forn(i, n){
  	cin >> a[i];
  	s.insert(a[i]);
  }
  
  // The algorithm uses the idea that the when gdc with the next number
  // it seems that are related or not, we can use the recurrence for the next 
  // numbers
  
  
  int m;
  while(n > 1){
    for (int i = 1; i < n; i++){
      b[i - 1] = __gcd(a[i], a[i - 1]);
    }
    
    int m = 0;
    for(int i = 0; i < n - 1; i++){
      // This line is to simplify the verification that i can start
      // to verify in the second position
      if (i && b[i] == b[i - 1]) continue;
      a[m++] = b[i];
    }
    forn(i, m) s.insert(a[i]);
    n = m;
  }
   
  cout << s.size() << endl;
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