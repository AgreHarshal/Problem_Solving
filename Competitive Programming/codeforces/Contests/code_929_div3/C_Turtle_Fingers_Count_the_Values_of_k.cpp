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
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
int integerPow(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; ++i)
    {
        result *= base;
    }
    return result;
}
void solve()
{
    int a, b, l;
    cin >> a >> b >> l;
    int res = 0;
    int x = 0;
    map<int, int> mp;
    // cout << l << endl;
    while (x < 20)
    {

        int y = 0;
        while (y < 20)
        {
            int a_x = (int)(0.5 + pow(a, x));
            int b_y = (int)(0.5 + pow(b, y));
            int mul = a_x * b_y;
            int div = l / mul;
            int mod = l % mul;
            // cout << x << " " << a_x << " " << y << " " << b_y << " " << div << " " << mul << endl;
            if (mod == 0 && mp.count(div) == 0)
            {
                // cout << div << " ";
                mp[div]++;
                res++;
                y++;
                // cout << "new";
            }
            else if (mod == 0)
            {
                // cout << "inc";
                y++;
            }
            else
            {
                // cout << "br";
                break;
            }
            // cout << "y" << y << " ";
        }
        x++;
    }
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