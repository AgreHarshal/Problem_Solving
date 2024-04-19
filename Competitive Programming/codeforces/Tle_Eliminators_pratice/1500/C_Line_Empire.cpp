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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i == 0)
        {
            pre[i] = arr[i];
        }
        else
        {
            pre[i] = pre[i - 1] + arr[i];
        }
    }
    int res = pre[n - 1] * b;
    for (int i = 0; i < n; i++)
    {
        int cal = arr[i] * b + arr[i] * a;
        // cout << cal << " ";
        // cout << pre[n - 1] - pre[i] << " ";
        cal += (b * (pre[n - 1] - pre[i] - (n - i - 1) * arr[i]));
        // cout << i << " " << cal << endl;
        res = min(res, cal);
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