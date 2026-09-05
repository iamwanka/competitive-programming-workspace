#include <bits/stdc++.h>
using namespace std;

#define int long long

void _solve()
{
    string s;
    cin >> s;

    int cnt = 0;
    int mn = 1e18;

    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(')
        {
            cnt++;
        }
        else if (s[i] == ')')
        {
            cnt--;
        }
        else if (isdigit(s[i]))
        {
            if (mn == 1e18)
            {
                mn = cnt;
            }
        }
        else
        {
            if (cnt > mn)
            {
                s[i] = '+';
            }
            else
            {
                s[i] = '-';
            }
        }

        if (mn != 1e18)
            mn = min(mn, cnt);
    }

    cout << s << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--)
        _solve();

    return 0;
}
