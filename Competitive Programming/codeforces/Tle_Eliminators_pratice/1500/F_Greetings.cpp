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
    vector<pair<int, int>> arr(n);
    vector<int> cp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        cin >> arr[i].second;
        cp[i] = arr[i].second;
    }
    sort(arr.begin(), arr.end());
    sort(cp.begin(), cp.end());
    int res = 0;
    // for (auto j : cp)
    // {
    //     cout << j << " ";
    // }
    // cout << endl;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(cp.begin(), cp.end(), arr[i].second);
        int add = it - cp.begin();
        // cout << arr[i].first << " " << add << endl;
        res += add;
        cp.erase(it);
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