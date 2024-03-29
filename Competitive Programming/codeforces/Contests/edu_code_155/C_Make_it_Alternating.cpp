#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
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
int fac(int n)
{
    if (n >= mod)
        return 0;

    int result = 1;
    for (int i = 1; i <= n; i++)
        result = (result * i) % mod;

    return result;
}
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int count1 = 0;
    int count0 = 0;
    vector<int> help;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            count1++;
        }
        else
        {
            if (count1)
            {
                help.push_back(count1);
            }
            count1 = 0;
        }
    }
    if (count1)
    {
        help.push_back(count1);
    }
    vector<int> hr;
    count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            count1++;
        }
        else
        {
            if (count1)
            {
                hr.push_back(count1);
                count1 = 0;
            }
        }
    }
    if (count1)
    {
        hr.push_back(count1);
    }
    int res1 = 0;
    int res2 = 1;
    for (auto i : help)
    {
        (res1 += (i - 1)) %= mod;
        (res2 *= i) %= mod;
    }
    for (auto i : hr)
    {
        (res1 += (i - 1)) %= mod;
        (res2 *= i) %= mod;
    }
    res2 *= fac(res1);
    res2 %= mod;
    cout << res1 << " " << res2 << endl;
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