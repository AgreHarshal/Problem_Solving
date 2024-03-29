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
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            string temp = "";
            string temp1 = "";
            for (int j = 0; j < i; j++)
            {
                temp += s[j];
            }
            for (int j = i; j < 2 * i; j++)
            {
                temp1 += s[j];
            }
            int diff = 0;
            int diff1 = 0;
            for (int j = 0; j < n; j++)
            {
                if (s[j] != temp[j % i])
                {
                    diff++;
                }
                if (s[j] != temp1[j % i])
                {
                    diff1++;
                }
                if (diff > 1 && diff1 > 1)
                {
                    break;
                }
            }
            if (diff <= 1 || diff1 <= 1)
            {
                cout << i << endl;
                return;
            }
        }
    }
    cout << n << endl;
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