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
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    dp[n - 1] = (arr[n - 1] == 0 ? 0 : 1);
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = min(dp[i], 1 + dp[i + 1]);
        if (i + arr[i] + 1 <= n)
        {
            dp[i] = min(dp[i], dp[i + arr[i] + 1]);
        }
    }
    cout << dp[0] << endl;
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