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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(32, 0));
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < 32; j++)
        {
            if (i != 0)
            {
                if (arr[i] & (1 << j))
                {
                    dp[i][j]++;
                    dp[i][j] += dp[i - 1][j];
                }
                else
                {
                    dp[i][j] += dp[i - 1][j];
                }
            }
            else
            {
                if (arr[i] & (1 << j))
                {
                    dp[i][j]++;
                }
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < 32; j++)
        {
            // cout << i << " " << j << " " << dp[i][j] << " " << dp[n - 1][j] << " " << dp[n - 1][j] - dp[i][j] << endl;
            if (dp[i][j] % 2 != (dp[n - 1][j] - dp[i][j]) % 2)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
            return;
        }
    }
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            bool flag = true;
            for (int k = 0; k < 32; k++)
            {
                if (dp[i][k] % 2 == (dp[j][k] - dp[i][k]) % 2 && (dp[j][k] - dp[i][k]) % 2 == (dp[n - 1][k] - dp[j][k]) % 2)
                {
                    continue;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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