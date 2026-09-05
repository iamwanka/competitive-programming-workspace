//g++ -std=c++17 -Wall -Wextra -O2 -DLOCAL main.cpp -o main && ./main < in.txt
#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl

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

void solve1() {
	int totalRows, costForEachRow, costRepairSail, distanceBreak;
	cin >> totalRows >> costForEachRow >> costRepairSail >> distanceBreak;
	vector<int> forecast(totalRows), pref(totalRows + 1);
	
	for (auto &i : forecast) cin >> i;

	
	for (int i = 0; i < totalRows; i++){
		pref[i + 1] = pref[i] + forecast[i];
	}	
	
	// Why preffix function works
	/*
		[l, r)
		
	*/


	int lastRepair = -1;
	ll costTotal = 0;
	ll totalCost = totalRows * costForEachRow;
	ll totalProfit = 0;

	for (int i = 0; i < totalRows;) {
		int end = min(totalRows, i + distanceBreak);
		int ones = pref[end] - pref[i];
		
		cout << i << " " << ones << endl;
		int profit = ones * costForEachRow - costRepairSail;
		// I compare if using the ones and his cost for each row
		// versus costRepairSail
		
		if (profit > 0)	{
			totalProfit += profit;
			i += distanceBreak;
		}
		else i++;
		
	}
	cout << totalCost - totalProfit << endl;

}

void solve() {
    int n, x, r, d;
    cin >> n >> x >> r >> d;

    vector<int> w(n+1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    vector<long long> pref(n+1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i-1] + w[i];

    const long long INF = 1e18;
    vector<long long> dp(n+1, INF);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {

        // Row
        dp[i] = dp[i-1] + x;

        // Repair window ending at i
        if (i >= d) {
            long long ones = pref[i] - pref[i-d];
            long long zeros = d - ones;
            long long cost = dp[i-d] + r + zeros * x;
            dp[i] = min(dp[i], cost);
        }
    }

    cout << dp[n] << "\n";
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