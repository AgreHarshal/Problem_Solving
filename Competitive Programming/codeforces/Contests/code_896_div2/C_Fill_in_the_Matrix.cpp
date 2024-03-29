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
    int n, m;
    cin >> n >> m;
    if (n >= m - 1)
    {
        if (m == 1)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << m << endl;
        }

        int p = 1;
        for (int i = 0; i < n; i++)
        {
            if (p % m == 0)
            {
                p++;
            }
            int pp = p;
            for (int j = 0; j < m; j++)
            {
                cout << pp % m << " ";
                pp++;
            }
            p++;
            cout << endl;
        }
    }
    else
    {

        cout << n + 1 << endl;

        int p = 1;
        for (int i = 0; i < n; i++)
        {
            if (p % m == 0)
            {
                p++;
            }
            int pp = p;
            for (int j = 0; j < m; j++)
            {
                cout << pp % m << " ";
                pp++;
            }
            p++;
            cout << endl;
        }
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