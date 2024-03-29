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
    string s;
    cin >> s;
    stack<char> q;
    int n = s.size();
    bool two = false;
    if (s == "()")
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] == '(' && s[i + 1] == '(') || (s[i] == ')' && s[i + 1] == ')'))
        {
            two = true;
        }
    }
    string ans = "";
    cout << "YES" << endl;
    if (two)
    {
        for (int i = 0; i < 2 * n; i += 2)
        {
            ans += '(';
            ans += ')';
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            ans += '(';
        }
        for (int i = 0; i < n; i++)
        {
            ans += ')';
        }
    }
    cout << ans << endl;
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