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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, int> mp;
    vector<int> put(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i]) != mp.end())
        {
            put[arr[i]] = max(put[arr[i]], (i - mp[arr[i]]));
            mp[arr[i]] = i;
        }
        else
        {
            mp[arr[i]] = i;
            put[arr[i]] = i + 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp.find(i) != mp.end())
        {
            put[i] = max(put[i], n - mp[i]);
        }
        else
        {
            put[i] = n + 1;
        }
    }
    vector<int> res(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        int start = put[i];
        for (int j = start; j <= n; j++)
        {
            if (res[j] != -1)
            {
                break;
            }
            else
            {
                res[j] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++)
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