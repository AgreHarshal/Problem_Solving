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
vector<int> f(vector<int> &arr, int n, int k)
{
    vector<int> res(n + 1, 0);
    int i = 0;
    int sum = 0;
    while (i < n)
    {
        if (arr[i] == 1)
        {
            sum++;
        }
        else
        {
            for (int j = 1; j <= sum; j++)
            {
                res[j] += (sum - j + 1);
            }
            sum = 0;
        }
        i++;
    }
    for (int j = 1; j <= sum; j++)
    {
        res[j] += (sum - j + 1);
    }
    return res;
}
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vector<int> aa = f(a, n, k);
    vector<int> bb = f(b, m, k);
    int res = 0;
    for (int i = 1; i * i <= k; i++)
    {
        if (k % i == 0 && i < aa.size() && k / i < bb.size())
        {
            res += (aa[i] * bb[k / i]);
        }
        if (k % i == 0 && i < bb.size() && k / i < aa.size() && (i * i) != k)
        {
            res += (bb[i] * aa[k / i]);
        }
    }
    cout << res << endl;
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(10);
    precal();
    solve();
    // int tc;
    // cin >> tc;
    // for (int t = 1; t <= tc; t++)
    // {
    //     // cout << 'CASE' << t << ':' ;
    //     solve();
    // }
    return 0;
}