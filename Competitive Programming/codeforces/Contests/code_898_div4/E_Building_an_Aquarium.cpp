#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
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
int water(vector<int> &arr, int mid)
{
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (mid >= arr[i])
        {
            res += (mid - arr[i]);
        }
    }
    return res;
}
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int high = 1e15;
    int low = 0;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int res = water(arr, mid);

        if (res <= x)
        {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
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