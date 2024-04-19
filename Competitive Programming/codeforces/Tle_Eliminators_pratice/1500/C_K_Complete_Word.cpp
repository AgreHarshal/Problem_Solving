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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    string s;
    cin >> s;
    vector<vector<int>> dp(k, vector<int>(26, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i % k][s[i] - 'a']++;
    }
    string comp = "";
    for (int i = 0; i <= k / 2; i++)
    {
        int maxi = 0;
        int max_ele = 0;
        for (int j = 0; j < 26; j++)
        {
            if (dp[i][j] + dp[k - i - 1][j] > maxi)
            {
                maxi = dp[i][j] + dp[k - i - 1][j];
                max_ele = j;
            }
        }
        comp += ('a' + max_ele);
    }

    if (k % 2)
    {
        char last = comp[comp.size() - 1];
        comp.pop_back();
        string rev = comp;
        reverse(rev.begin(), rev.end());
        comp += last;
        comp += rev;
    }
    else
    {
        comp.pop_back();
        string rev = comp;
        reverse(rev.begin(), rev.end());
        comp += rev;
    }
    // cout << comp << endl;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != comp[i % k])
        {
            res++;
        }
    }
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