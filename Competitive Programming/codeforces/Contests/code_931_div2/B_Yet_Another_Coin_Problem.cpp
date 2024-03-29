#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
vector<int> dp(31, -1);
vector<int> arr(5);
void precal()
{

    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 6;
    arr[3] = 10;
    arr[4] = 15;
    dp[0] = 0;
    for (int i = 1; i <= 30; i++)
    {
        int mini = INT_MAX;
        for (int j = 0; j < 5; j++)
        {
            if (i - arr[j] >= 0 && dp[i - arr[j]] != -1)
            {
                mini = min(mini, dp[i - arr[j]]);
            }
        }
        if (mini < INT_MAX)
        {
            dp[i] = 1 + mini;
        }
    }
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
    int res = n / 15;
    int rem = n % 15;
    if (n <= 30)
    {
        cout << dp[n] << endl;
    }
    else if (rem == 0)
    {
        cout << res << endl;
    }
    else
    {
        cout << res - 1 + dp[15 + rem] << endl;
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