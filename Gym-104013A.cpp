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
	int n; cin >> n;
	map<int, string> mp = {
		
    {1995, "ITMO"},
    {1996, "SPbSU"},
    {1997, "SPbSU"},
    {1998, "ITMO"},
    {1999, "ITMO"},
    {2000, "SPbSU"},
    {2001, "ITMO"},
    {2002, "ITMO"},
    {2003, "ITMO"},
    {2004, "ITMO"},
    {2005, "ITMO"},
    {2006, "PetrSU, ITMO"},
    {2007, "SPbSU"},
    {2008, "SPbSU"},
    {2009, "ITMO"},
    {2010, "ITMO"},
    {2011, "ITMO"},
    {2012, "ITMO"},
    {2013, "SPbSU"},
    {2014, "ITMO"},
    {2015, "ITMO"},
    {2016, "ITMO"},
    {2017, "ITMO"},
    {2018, "SPbSU"},
    {2019, "ITMO"},
	};
	
	// int n; cin >> n;
	cout << mp[n] << endl;
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