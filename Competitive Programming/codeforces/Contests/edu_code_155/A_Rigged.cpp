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
    vector<int> s(n);
    vector<int> e(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        cin >> e[i];
    }
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (e[i] >= e[0] && s[i] >= s[0])
        {
            flag = true;
        }
    }
    if (flag)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << s[0] << endl;
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