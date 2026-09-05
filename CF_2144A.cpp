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
  vi a(n);
  for(auto &i: a) cin >> i;
  vi pf(n + 1);
forn(i, n){
	pf[i + 1] = a[i] + pf[i];
}
	
	forab(i, 1, n - 1){
		int p1 = pf[i] % 3;
		forab(j, i + 1, n){
			int p2 = (pf[j] - pf[i]) % 3;
			int p3 = (pf[n] - p2 - p1) % 3;
			if (p1 == p2 && p2 == p3 || (p1 != p2 && p2 != p3 && p1 != p3)) {
				cout << i << " " << j << endl;
				return;
			}
			
		}
	}
	cout << "0 0 "<<endl;
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