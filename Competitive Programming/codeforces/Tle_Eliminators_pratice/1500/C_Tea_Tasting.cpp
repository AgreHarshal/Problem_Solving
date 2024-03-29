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
    vector<int> tea(n);
    vector<int> taste(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tea[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> taste[i];
    }
    vector<int> pre(n, 0);
    pre[0] = taste[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + taste[i];
    }
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(pre.begin(), pre.end(), tea[i]);
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