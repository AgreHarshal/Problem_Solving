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
    int x, y, n;
    cin >> x >> y >> n;
    if (y < x + n * (n - 1) / 2)
    {
        cout << "-1" << endl;
    }
    else
    {
        vector<int> res;
        int ans = y;
        int diff = 1;
        for (int i = 0; i < n - 1; i++)
        {
            res.push_back(ans);
            ans -= diff;
            diff++;
        }
        res.push_back(x);
        reverse(res.begin(), res.end());
        for (int i = 0; i < n; i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
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