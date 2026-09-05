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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w, h;
    int s;
    cin >> n >> w >> h >> s;

    string final_answer = "";

    forn(i, n) {
        int maxi = 0;
        char x; cin >> x;
        string str;
        forn(j, h) {
            cin >> str;
            int c = 0, st = 0;
            forn(k, w) {
                if (str[k] == '#' && st == 0) {
                    c++;

                    st = 1;
                }

                else if (str[k] == '.' && st == 1) {
                    c++;
                    st = 0;
                }
            }
            if (st == 1) c++;
            maxi = max(c, maxi);

        }
        string ans = string( (s + maxi - 1)/maxi, x);
        if (final_answer == "" || final_answer.size() > ans.size())
            final_answer = ans;

    }
    cout << final_answer << endl;
}
