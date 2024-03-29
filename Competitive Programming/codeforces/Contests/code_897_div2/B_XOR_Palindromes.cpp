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
// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int t = 0;
    int i = 0;
    while (i < n / 2)
    {
        if (s[i] != s[n - i - 1])
        {
            t++;
        }
        i++;
    }
    vector<int> res(n + 1);
    for (int i = 0; i <= n; i++)
    {
        if (i < t)
        {
            res[i] = 0;
        }
        else
        {
            int mid = i - t;
            if (n % 2)
            {
                if (mid <= n - 2 * t)
                {
                    res[i] = 1;
                }
                else
                {
                    res[i] = 0;
                }
            }
            else
            {
                if (mid <= n - 2 * t && mid % 2 == 0)
                {
                    res[i] = 1;
                }
                else
                {
                    res[i] = 0;
                }
            }
        }
    }
    for (auto j : res)
    {
        cout << j;
    }
    cout << endl;
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