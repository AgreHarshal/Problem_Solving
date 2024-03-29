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
    int l, r;
    cin >> l >> r;
    if (r == 1 || r == 2 || r == 3)
    {
        cout << "-1" << endl;
        return;
    }
    else
    {
        for (int i = r; i >= l; i--)
        {
            if (i % 2 == 0)
            {
                cout << i / 2 << " " << i / 2 << endl;
                return;
            }
            else
            {
                for (int j = 2; j * j <= i; j++)
                {
                    if ((i % j) == 0)
                    {
                        cout << j << " " << (i - j) << endl;
                        return;
                    }
                }
            }
        }
        cout << "-1" << endl;
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