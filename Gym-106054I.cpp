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

void solve() {
	int n, m; cin >> n >> m;
	int pointsInes = 0;
	vector<int> final_points(n);
	while (m--) {
		int a, b; cin >> a >> b;
		int countA = 0;
		vector<int> v(n);
		for (auto &i : v) {
			cin >> i;
			if (i == 1) countA++;
		}
		int goldByChooseA = a / (countA + 1);
		bool check = 0;
		if (goldByChooseA >= b) pointsInes += goldByChooseA, check = 1;
		else pointsInes += b;

		// The other players
		forn(i, n)
		if (v[i] == 1) {
			if (check) final_points[i] += goldByChooseA;
			else final_points[i] += a / countA;
		}
		else final_points[i] += b;
	}
	
	for (auto i: final_points) cout << i << " "; cout << pointsInes;
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