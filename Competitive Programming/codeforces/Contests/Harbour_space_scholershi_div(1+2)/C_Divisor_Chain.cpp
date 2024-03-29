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
    vector<int> res;
    res.push_back(n);
    while ((n & (n - 1)) != 0)
    {
        int first_set = __builtin_ctz(n);
        int sum = (1 << first_set);
        n -= sum;
        res.push_back(n);
    }
    int k = __builtin_ctz(n);
    for (int i = k - 1; i >= 0; i--)
    {
        int sub = (1 << i);
        n -= sub;
        res.push_back(n);
    }
    cout << res.size() << endl;
    for (auto i : res)
    {
        cout << i << " ";
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