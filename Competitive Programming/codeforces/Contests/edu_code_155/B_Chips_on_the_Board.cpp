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
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int a_min = *(min_element(a.begin(), a.end()));
    int b_min = *(min_element(b.begin(), b.end()));
    int res1 = 0;
    int res2 = 0;
    res1 = accumulate(b.begin(), b.end(), 0ll);
    res1 = res1 + n * a_min;
    res2 = accumulate(a.begin(), a.end(), 0ll);
    res2 = res2 + n * b_min;
    if (res1 < res2)
    {
        cout << res1 << endl;
    }
    else
    {
        cout << res2 << endl;
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