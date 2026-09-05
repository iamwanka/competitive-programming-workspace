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



void solve() {
	int n; cin >> n;
	struct Horizontal_Line {
		// Las lineas horizontales tienen el y igual
		int y, x1, x2;
	};

	struct Vertical_Line {
		// Las lineas verticales tienen el x igual
		int x, y1, y2;
	};

	vector<Horizontal_Line> H;
	vector<Vertical_Line> V;

	forn(i, n) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) {
			if (y1 > y2) swap(y1, y2);
			V.pb({x1, y1, y2});

		}
		else {
			if (x1 > x2) swap(x1, x2);
			H.pb({y1, x1, x2});
		}
	}
	long long ans = 0;
	
	/*
		
	*/
	
    if (V.size() <= H.size()) {
        // vertical-pair strategy
        vector<bitset<5000>> inter(V.size());

        for (int v = 0; v < (int)V.size(); v++) {
            for (int h = 0; h < (int)H.size(); h++) {
                if (H[h].x1 <= V[v].x && V[v].x <= H[h].x2 &&
                    V[v].y1 <= H[h].y && H[h].y <= V[v].y2) {
                    inter[v].set(h);
                }
            }
        }

        for (int i = 0; i < (int)V.size(); i++) {
            for (int j = i + 1; j < (int)V.size(); j++) {
                int c = (inter[i] & inter[j]).count();
                ans += 1LL * c * (c - 1) / 2;
            }
        }
    } else {
        // horizontal-pair strategy
        vector<bitset<5000>> inter(H.size());

        for (int h = 0; h < (int)H.size(); h++) {
            for (int v = 0; v < (int)V.size(); v++) {
                if (H[h].x1 <= V[v].x && V[v].x <= H[h].x2 &&
                    V[v].y1 <= H[h].y && H[h].y <= V[v].y2) {
                    inter[h].set(v);
                }
            }
        }

        for (int i = 0; i < (int)H.size(); i++) {
            for (int j = i + 1; j < (int)H.size(); j++) {
                int c = (inter[i] & inter[j]).count();
                ans += 1LL * c * (c - 1) / 2;
            }
        }
    }

    cout << ans << '\n';
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