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


int R, C;
int grid[105][105];
int dp[105][105];
int dx[4]  = {1, -1, 0, 0};
int dy[4]  = {0, 0, 1, -1};

int solve(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 1;

	forn(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

		if (grid[nx][ny] > grid[x][y]) dp[x][y] = max(dp[x][y], 1 + solve(nx, ny));
	}

	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;
	forn(i, R) forn(j, C) cin >> grid[i][j];
	
	memset(dp, -1, sizeof(dp));
	
	int answer = 0;
	forn(i, R) forn(j, C) answer = max(answer, solve(i, j));
	
	cout << answer << endl;
	return 0;
}