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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    precal();

    vector<int> x1(n, 0);
    vector<int> x2(n, 0);
    if (s[0] == '1')
    {
        x2[0] = a[0];
    }
    else
    {
        x1[0] = a[0];
    }
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0')
        {
            x1[i] = x1[i - 1] ^ a[i];
            x2[i] = x2[i - 1];
        }
        else
        {
            x2[i] = x2[i - 1] ^ a[i];
            x1[i] = x1[i - 1];
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int l, r;
            cin >> l >> r;
        }
        else
        {
            int p;
            cin >> p;
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