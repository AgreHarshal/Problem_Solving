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
    int common_divisor = gcd(abs(numerator), abs(denominator));
    numerator /= common_divisor;
    denominator /= common_divisor;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<long double> c;
    int freq = 0;
    int cal = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 && b[i] == 0)
        {
            cal++;
        }
        else if (a[i] != 0)
        {
            long double cal = (1.0 * b[i]) / (1.0 * a[i]);
            // cout << cal << endl;
            c.push_back(cal);
        }
    }
    sort(c.begin(), c.end());
    int curr = (c.size() >= 1 ? 1 : 0);

    for (int i = 1; i < c.size(); i++)
    {
        if (c[i] == c[i - 1])
        {
            curr++;
        }
        else
        {
            freq = max(freq, curr);
            curr = 1;
        }
    }
    freq = max(freq, curr);
    cout << freq + cal << endl;
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