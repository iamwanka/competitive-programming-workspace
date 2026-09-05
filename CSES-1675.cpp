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

 class DisjointSets {

  private:

	vector<int> parents;

	vector<int> sizes;


  public:

	DisjointSets(int size) : parents(size), sizes(size, 1) {

		for (int i = 0; i < size; i++) { parents[i] = i; }

	}


	int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }


	bool unite(int x, int y) {

		int x_root = find(x);

		int y_root = find(y);

		if (x_root == y_root) { return false; }


		if (sizes[x_root] < sizes[y_root]) { std::swap(x_root, y_root); }

		sizes[x_root] += sizes[y_root];

		parents[y_root] = x_root;

		return true;

	}


	bool connected(int x, int y) { return find(x) == find(y); }

};



void solve(){
  int n, m; cin >> n >> m;
  
  struct Road {
  	int c1, c2;
  	int cost;
  };
  
  vector<Road> roads(m);
  for(Road &i: roads) {
  	cin >> i.c1 >> i.c2 >> i.cost;
  	i.c1--;
  	i.c2--;
  }
  
  sort(all(roads), [&] (Road &a, Road &b) {
  	return a.cost < b.cost;
  });
  
  DisjointSets network(n);
  long long min_cost = 0;
  int added = 0;
  
  for(Road &i: roads){
  	bool status = network.unite(i.c1, i.c2);
    // cout << i.c1 << " " << i.c2 << " " << i.cost << (status? "si": "no")<< endl;

  	min_cost += i.cost * status;
  	added += status; 
  }
  
  if (added < n - 1) {
  	cout << "IMPOSSIBLE" << endl;
  }
  else cout << min_cost << endl; 
  
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