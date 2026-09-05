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

#include <bits/stdc++.h>
using namespace std;

// BeginCodeSnip{Segment Tree}
/** A data structure that can answer point update & range max queries. */
template <class T> class MaxSegmentTree {
  private:
	// const T DEFAULT = std::numeric_limits<T>().max();
	const T DEFAULT = 0;

	int len;
	vector<T> segtree;

  public:
	MaxSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = std::max(segtree[ind], segtree[ind ^ 1]);
		}
	}

	T range_max(int start, int end) {
		T max = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { max = std::max(max, segtree[start++]); }
			if (end % 2 == 1) { max = std::max(max, segtree[--end]); }
		}
		return max;
	}
};
// EndCodeSnip

// BeginCodeSnip{HLD}
template <class T, bool VALS_IN_EDGES> class HLD {
  private:
	int N, R, tim = 0;  // n, root node, time
	vector<vector<int>> adj;
	vector<int> par, siz, depth, rt, pos;  // parent, size, depth, root, position arrays
	MaxSegmentTree<T> segtree;             // Modify as needed

	/** Compute the size of each subtree and set parent-child relationship
	 * Subtree of node v corresponds to segment [ pos[v], pos[v] + sz[v] ) */
	void dfs_sz(int v) {
		if (par[v] != -1) adj[v].erase(find(adj[v].begin(), adj[v].end(), par[v]));
		for (int &u : adj[v]) {
			par[u] = v, depth[u] = depth[v] + 1;
			dfs_sz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}

	/** Assign positions for nodes
	  * Path from v to the last vertex in ascending heavy path
	    corresponds to [ pos[rt[v]], pos[v] ] */
	void dfs_hld(int v) {
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfs_hld(u);
		}
	}

	/** process all heavy path and combine their results */
	template <class B> void process(int u, int v, B op) {
		for (; rt[u] != rt[v]; v = par[rt[v]]) {
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
			op(pos[rt[v]], pos[v]);
		}
		if (depth[u] > depth[v]) swap(u, v);
		op(pos[u] + VALS_IN_EDGES, pos[v]);
	}

  public:
	HLD(vector<vector<int>> adj_, int _R)
	    : N(adj_.size()), R(_R), adj(adj_), par(N, -1), siz(N, 1), depth(N), rt(N),
	      pos(N), segtree(N)  // modify as needed
	{
		rt[R] = R;
		dfs_sz(R);
		dfs_hld(R);
	}

	T query_path(int u, int v) {
		T res = 0;  // default value, modify depending on problem
		process(u, v, [&](int l, int r) {
			res = max(res, segtree.range_max(l, r + 1));  // modify depending on problem
		});
		return res;
	}

	void modify_node(int u, T val) { segtree.set(pos[u], val); }
};
// EndCodeSnip

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	vector<vector<int>> adj(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	HLD<int, 0> H(adj, 0);

	for (int i = 0; i < n; i++) { H.modify_node(i, v[i]); }

	while (q--) {
		int type, s, x;
		cin >> type;
		if (type == 1) {
			cin >> s >> x;
			--s;
			H.modify_node(s, x);
		} else if (type == 2) {
			cin >> s;
			--s;
			cout << H.query_path(0, s) + H.query_path(1,0) << "\n";
		}
	}
}
