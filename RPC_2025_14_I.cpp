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

const int N = 1e5 + 5;
int a[N], n, k;

ll calc (ll mid) {
    // What's the purpose of this function:
    // count the number of pair that are their sums
    // are less or equal to mid
    
    ll ans = 0;
    int j = n - 1; // pointer 
    for(int i = 0; i < n; i++){
        while(j >= 0 && a[i] + a[j] > mid) j--;
        ans += j + 1;
    }
    return ans;
}

void solve(){
  cin >> n >> k;
  forn(i, n) cin >> a[i];
  sort(a, a + n);
  
  ll l = 2*a[0], r = 2*a[n - 1], ans = l;
  while (l <= r){
    ll mid = l + (r - l) / 2;
    
    if (calc(mid) < k) l = mid + 1;
    else ans = mid, r = mid - 1;
  }
  cout << ans << endl;
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