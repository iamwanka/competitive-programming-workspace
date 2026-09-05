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
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

void solve(){
  int n, w; cin >> n >> w;
  vector<ii> vi(n);
  
  forn(i, n) {
  	int p, t;
  	cin >> p >> t;
  	vi[i] = {p, t};
  }
  
  // for(auto &i: vi) cout << i.ff << " " << i.ss << endl;
  
  auto check = [&] (ld time_limit) -> bool {
  	ld ans = 0.0; // La suma de cada capacidad de cada tolva
  	// si ans >= w, es decir la suma de la capacidad total de cada tolva
  	// supera o iguala a lo que necesito es posible hacerlo
    
    // cout << time_limit << endl;	
  	for (ii a: vi) {
  		ld capacity = 0.0; // capacidad por tolva dentro de tiempo limite
  		int p = a.first, t = a.second;
  		// capacity += 2*t;
  		
      
  		// la capacidad, es decir lo que puede pasar en el tiempo limite
  		capacity = max<ld>(0, time_limit - 2*t) * p;
  		// cout << p << " " << t << " " << capacity << endl;
      ans += capacity;
      
      if (ans >= w) return true;
  	}
    
    // cout << endl;
    return ans >= w;
  };
  
  ld l = 0.0, r = 1e10;
  forn(i, 64) {
  	ld mid =  (l + r) / 2;
    // cout << mid << endl;	
  	if (check(mid)) {
  		r = mid;
  	}
  	else l = mid;
  }
  cout << setprecision(12);
  cout << l << endl;
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