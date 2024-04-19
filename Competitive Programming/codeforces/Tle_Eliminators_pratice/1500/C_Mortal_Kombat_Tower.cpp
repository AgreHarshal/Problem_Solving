// have to use dp in here ,we cant go greedy as we dont know about fuutre self

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
int f(vector<int> &arr, int i, int turn, int n, vector<vector<int>> &dp)
{
    if (i >= n)
    {
        return 0;
    }
    if (dp[i][turn] != -1)
    {
        return dp[i][turn];
    }
    int mini = 1e9;
    if (turn)
    {

        if (arr[i] == 0)
        {
            mini = min(mini, f(arr, i + 1, turn ^ 1, n, dp));
        }
        if (arr[i] == 1)
        {
            mini = min(mini, f(arr, i + 1, turn ^ 1, n, dp) + 1);
        }
        if (i + 1 < n && arr[i] == 1 && arr[i + 1] == 0)
        {
            mini = min(mini, f(arr, i + 2, turn ^ 1, n, dp) + 1);
        }
        if (i + 1 < n && arr[i] == 0 && arr[i + 1] == 1)
        {
            mini = min(mini, f(arr, i + 2, turn ^ 1, n, dp) + 1);
        }
        if (i + 1 < n && arr[i] == 0 && arr[i + 1] == 0)
        {
            mini = min(mini, f(arr, i + 2, turn ^ 1, n, dp));
        }
        if (i + 1 < n && arr[i] == 1 && arr[i + 1] == 1)
        {
            mini = min(mini, f(arr, i + 1, turn ^ 1, n, dp) + 2);
        }
    }
    else
    {
        mini = min(f(arr, i + 1, turn ^ 1, n, dp), f(arr, i + 2, turn ^ 1, n, dp));
    }
    return dp[i][turn] = mini;
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
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    int res = f(arr, 0, 1, n, dp);
    cout << res << endl;
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