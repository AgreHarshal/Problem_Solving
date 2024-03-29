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
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    int res1 = 0;
    sort(arr.begin(), arr.end());
    vector<int> res(n);
    for (int j = 0; j < n; j++)
    {
        res1 += abs(arr[0].first - arr[j].first) + 1;
    }

    res[arr[0].second] = res1;
    for (int i = 1; i < n; i++)
    {
        int diff = arr[i].first - arr[i - 1].first;
        res1 -= ((n - i - 1) * diff);
        res1 += ((i - 1) * diff);
        res[arr[i].second] = res1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
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