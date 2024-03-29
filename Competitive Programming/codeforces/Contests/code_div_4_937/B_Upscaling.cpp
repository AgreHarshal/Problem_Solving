#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
void precal()
{
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> dp(2 * n, vector<char>(2 * n));
    char val1 = '#';
    char val2 = '.';
    char res = val1;
    for (int i = 0; i < 2 * n; i++)
    {
        char start = res;
        for (int j = 0; j < 2 * n; j++)
        {
            dp[i][j] = res;
            if (j % 2)
            {
                if (res == val1)
                {
                    res = val2;
                }
                else
                {
                    res = val1;
                }
            }
        }
        if (i % 2)
        {
            if (dp[i][0] == val1)
            {
                res = val2;
            }
            else
            {
                res = val1;
            }
        }
        else
        {
            res = dp[i][0];
        }
    }

    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            cout << dp[i][j];
        }
        cout << endl;
    }
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(10);
    precal();
    // solve();
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << 'CASE' << t << ':' ;
        solve();
    }
    return 0;
}