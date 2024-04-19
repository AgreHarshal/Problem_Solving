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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int i = 0;
    // cout << "blahh" << endl;
    while (i < n)
    {
        if (i + k < n && s[i] != '?' && s[i + k] != '?' && s[i] != s[i + k])
        {
            cout << "NO" << endl;
            return;
        }
        else if (i + k < n && s[i] == '?' && s[i + k] != '?')
        {
            s[i] = s[i + k];
        }
        else if (i + k < n && s[i] != '?' && s[i + k] == '?')
        {
            s[i + k] = s[i];
        }
        i++;
    }
    i = n - 1;
    while (i >= 0)
    {
        if (i - k >= 0 && s[i] != '?' && s[i - k] != '?' && s[i] != s[i - k])
        {
            cout << "NO" << endl;
            return;
        }
        else if (i - k >= 0 && s[i] == '?' && s[i - k] != '?')
        {
            s[i] = s[i - k];
        }
        else if (i - k >= 0 && s[i] != '?' && s[i - k] == '?')
        {
            s[i - k] = s[i];
        }
        i--;
    }
    int one = 0, zero = 0, q = 0;
    i = 0;
    while (i < k)
    {
        if (s[i] == '0')
        {
            zero++;
        }
        else if (s[i] == '1')
        {
            one++;
        }
        else
        {
            q++;
        }
        i++;
    }
    // cout << one << " " << zero << " " << q << " " << s << endl;
    if (max(one, zero) - min(one, zero) > q)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        if ((q - (max(one, zero) - min(one, zero))) % 2)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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