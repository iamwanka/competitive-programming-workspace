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
  vector<int> a(n);
  // Algoritmo hecho a mano
  
  for(auto &i: a) cin >> i;
  vector<int> ans;
    ans.pb(0);
    
    int last_diff = 0;
    
    forn(i, n){
        int actual_diff = a[ans.back()] - a[i];
        if(actual_diff == 0) continue;
        
        if(last_diff == 0){
            ans.pb(i);
            last_diff = actual_diff;
        }
        else if ((actual_diff > 0 && last_diff < 0) || (actual_diff < 0 && last_diff > 0)){
           ans.pb(i);
           last_diff = actual_diff;
        }
        else{
            ans.back() = i;
        }
    }
    
    if (ans.size() < 3){
        cout << 0 << endl;
        return;
    }
    
    cout << ans.size() << endl;
    for(int i : ans) cout << i << " ";
    cout << endl;

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