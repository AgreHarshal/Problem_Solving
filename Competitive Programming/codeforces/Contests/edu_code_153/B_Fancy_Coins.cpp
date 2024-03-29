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
    int m, k, a_1, a_k;
    cin >> m >> k >> a_1 >> a_k;
    int res = 0;
    int m_req = m / k;
    if (m_req <= a_k)
    {
        m = m - m_req * k;
    }
    else
    {

        m = m - a_k * k;
    }
    if (m == 0)
    {
        cout << "0" << endl;
        return;
    }
    int m1_req = m;
    if (m1_req <= a_1)
    {
        m = m - m1_req;
    }
    else
    {
        int t1 = m % k;
        if (t1 <= a_1)
        {
            a_1 -= t1;
            m -= t1;
            m = m - (a_1 / k) * k;
        }
        else
        {
            m = m - a_1;
        }
    }
    if (m == 0)
    {
        cout << "0" << endl;
        return;
    }

    int ans1 = m / k;
    res += ans1;
    res += (m % k);
    cout << res << endl;
    return;
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