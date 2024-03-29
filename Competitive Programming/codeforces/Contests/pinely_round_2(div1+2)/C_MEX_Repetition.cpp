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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    set<int> s;
    for (int i = 0; i <= n; i++)
    {
        s.insert(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] <= n)
        {
            s.erase(arr[i]);
        }
    }
    vector<int> res(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        res[i] = *s.begin();
        s.erase(s.begin());
        s.insert(arr[i]);
    }
    res[n] = *s.begin();
    int i = 0;
    for (auto j : res)
    {
        cout << j << " ";
    }
    cout << endl;
    while (i < n)
    {
        cout << res[(k - 1 + i) % (n + 1)] << " ";
        i++;
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