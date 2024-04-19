#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int N = 40010;
vector<int> dp(N + 1, 0);
vector<int> flag(N + 1, 0);
bool ispalindrome(int p)
{
    int original = p;
    int reversed = 0;

    while (p > 0)
    {
        int digit = p % 10;
        reversed = reversed * 10 + digit;
        p /= 10;
    }

    return original == reversed;
}

void precal()
{

    dp[0] = 1;
    for (int i = 0; i < N; i++)
    {
        if (ispalindrome(i))
        {
            flag[i] = 1;
        }
    }
    for (int i = 1; i < N; i++)
    {
        // cout << "brujj" << endl;
        for (int j = j = i; j <= N; j++)
        {
            if (flag[i])
            {
                dp[j] = dp[j] + dp[j - i];
                dp[j] %= mod;
            }
            else
            {
                continue;
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    cout << dp[n] % mod << endl;
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