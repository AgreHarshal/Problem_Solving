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
int freq = 0;
int f(int i, vector<int> &nums, int n)
{
    if (i == n)
    {
        return 0;
    }
    int res = 0;
    int ans = 0;
    for (int j = i; j < n; j++)
    {
        ans += nums[j];
        cout << "added-" << ans << endl;
        int add = f(j + 1, nums, n);
        res = res + (n - i - 1) * ans + add;
        ans *= 10;
    }
    return res;
}
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        res[i] = s[i] - '0';
    }
    int ans = f(0, res, n);
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