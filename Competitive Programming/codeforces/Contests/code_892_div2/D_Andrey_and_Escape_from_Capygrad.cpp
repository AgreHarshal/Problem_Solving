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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[i].first = a;
        arr[i].second = d;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1].first <= arr[i].second)
        {
            arr[i].second = max(arr[i].second, arr[i + 1].second);
            arr[i + 1].second = max(arr[i].second, arr[i + 1].second);
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (arr[i].first <= arr[i - 1].second)
        {
            arr[i].second = max(arr[i].second, arr[i - 1].second);
            arr[i - 1].second = max(arr[i].second, arr[i - 1].second);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int pos;
        cin >> pos;
        int low = 0;
        int high = n - 1;
        int ans = pos;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid].first <= pos)
            {
                ans = max(arr[mid].second, ans);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << max(ans, pos) << " ";
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