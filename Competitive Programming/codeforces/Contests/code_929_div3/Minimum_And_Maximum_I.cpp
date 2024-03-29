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
int sum(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans += (arr[i] + arr[i + 1]);
    }
    return ans;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    int two = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        two += (2 * arr[i]);
    }
    while (q--)
    {
        int x;
        cin >> x;
        sort(arr.begin(), arr.end());
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