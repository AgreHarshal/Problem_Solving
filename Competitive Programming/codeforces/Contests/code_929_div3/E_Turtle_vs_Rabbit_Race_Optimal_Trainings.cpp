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
int ind(int u, int l, vector<int> &pre, int n, vector<int> &arr)
{

    int low = l, high = n;
    int res = l;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // cout << mid << "mid " << pre[mid] - pre[l - 1] << "sum ";
        if (pre[mid] - pre[l - 1] <= u)
        {
            // cout << "res-" << res << " ";
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (pre[res] - pre[l - 1] == u)
    {
        return res;
    }
    if (res + 1 <= n && (1.0 * arr[res]) / 2 <= (u - (pre[res] - pre[l - 1])))
    {
        return res + 1;
    }
    else
    {
        return res;
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + arr[i - 1];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, u;
        cin >> l >> u;
        int ans = ind(u, l, pre, n, arr);
        cout << ans << " ";
        ;
    }
    cout << endl;
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