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
    int n, x, y;
    cin >> n >> x >> y;
    int div = lcm(x, y);
    div = n / div;
    x = n / x;
    x -= div;
    y = n / y;
    y -= div;
    int res = 0;
    int add = n * (n + 1) / 2;
    int sub = (n - x) * (n - x + 1) / 2;
    res += add;
    res -= sub;

    res -= (y * (y + 1) / 2);
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