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
void simplifyFraction(int &numerator, int &denominator)
{
    int common_divisor = gcd(numerator, denominator);
    numerator /= common_divisor;
    denominator /= common_divisor;
}
void solve()
{
    int n;
    cin >> n;
    // vector<int> arr(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    string s;
    cin >> s;
    int q;
    cin >> q;
    int plus = 0;
    int minus = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+')
        {
            plus++;
        }
        else
        {
            minus++;
        }
    }
    int a, b;
    if (plus > minus)
    {
        b = plus;
        a = minus;
    }
    else
    {
        b = minus;
        a = plus;
    }
    while (q--)
    {

        int l, r;
        cin >> l >> r;
        if (a == b)
        {
            cout << "YES" << endl;
            continue;
        }
        simplifyFraction(l, r);
        int q1 = min(l, r);
        int p1 = max(l, r);
        if (p1 != q1 && (b - a) % (p1 - q1) == 0 && (a - ((b - a) / (p1 - q1)) * q1 >= 0))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
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
    solve();
    // int tc;
    // cin >> tc;
    // for (int t = 1; t <= tc; t++)
    // {
    //     // cout << 'CASE' << t << ':' ;
    //     solve();
    // }
    return 0;
}