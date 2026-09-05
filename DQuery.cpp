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
  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // La idea para la version offline
    // 1. Recibir todos las queries de antemano
    // 2. Procesar los sufijos, cada vez que termina en j,
    //	  puede procesar las queries guardadas
    
   	vector<int> a = {4, 573, 28, 4, 2, 3, 2, 5, 2, 54};
    
    vector<ii> queries = {
    	{2, 3},
    	{4, 5},
    	{6, 9},
    	{1, 9}
    };
    
    sort(all(queries), [] (ii a, ii b) {
    	return a.ss <= b.ss;
    });
    
    // Una estructura de datos que permite guardar y conocer la existencia
    // de elementos de manera dinamica
    
     
    return 0;
}