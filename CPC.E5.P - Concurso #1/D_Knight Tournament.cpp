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

// Implementación de punteros
const int N = 4e5;
int ans[N];
int nxt[N];

int find(int i) {
	// I want to find the element that has never been touched
	// by an array
	if (nxt[i] == i) return i;
	return nxt[i] = find(nxt[i]);
}


void solve() {
	int n, m; cin >> n >> m;

	for (int i = 1; i <= n + 1; i++)
		nxt[i] = i, ans[i] = 0;

	while (m--) {
		int l, r, x;
		cin >> l >> r >> x;
		// cout << l << " " << r << " " << x << endl;
		int pointer = find(l);
		while (pointer <= r) {
			if (pointer != x && ans[pointer] == 0) {
				ans[pointer] = x;
				// cout << pointer << endl;
				nxt[pointer] = pointer + 1;
				pointer = find(pointer);
			}
			else pointer = find(pointer + 1);
		}
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}