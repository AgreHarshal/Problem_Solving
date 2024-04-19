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
    string x, y;
    cin >> x >> y;
    // vector<int> arr(n);
    vector<int> a, b;
    int n = x.size();
    int i = 0;
    bool flag = true;
    while (i < n)
    {

        if (x[i] != y[i] && flag)
        {
            int maxi = max(x[i] - '0', y[i] - '0');
            int mini = min(x[i] - '0', y[i] - '0');
            x[i] = '0' + maxi;
            y[i] = '0' + mini;
            flag = false;
        }
        else if (x[i] != y[i])
        {
            int maxi = max(x[i] - '0', y[i] - '0');
            int mini = min(x[i] - '0', y[i] - '0');
            x[i] = '0' + mini;
            y[i] = '0' + maxi;
        }
        i++;
    }
    cout << x << endl
         << y << endl;
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