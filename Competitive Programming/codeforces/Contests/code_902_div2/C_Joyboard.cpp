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
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = (m >= n ? m / n + n - 1 : m);
    if (k == 1)
    {
        cout << "1" << endl;
    }
    else if (k == 2)
    {

        cout << cnt << endl;
    }
    else if (k == 3)
    {
        cout << (m >= n ? m - n - m / n + 1 : 0);
        cout << endl;
    }
    else
    {
        cout << "0" << endl;
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