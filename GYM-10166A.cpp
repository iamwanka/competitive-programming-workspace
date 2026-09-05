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

const long double PI = acos(-1);

struct node{
	int x,y;
	
	bool operator< (node b){
		if (x != b.x) return x < b.x;
		return y < b.y;
	}
};

void solve(){
  int m, n; cin >> m >> n;
  double r; cin >> r;
  
  node a, b;
  cin >> a.x >> a.y >> b.x >> b.y;
  swap(a, b);
  // cout << a.x << " " << a.y << endl;
  // cout << b.x << " " << b.y << endl;
  
  long double unit_ring = r / n;
  long double unit_semicircumference = (PI * min(a.y, b.y) * unit_ring) / m;
  // cout << fabs(a.y - b.y) << endl;
  // cout << unit_semicircumference << endl;
  long double manhatan_distance1 = unit_ring*fabs(a.y - b.y) + unit_semicircumference*fabs(a.x - b.x);
  long double manhatan_distance2 = unit_ring*(a.y + b.y);
  
  cout << setprecision(14) << min(manhatan_distance1, manhatan_distance2) << endl;
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