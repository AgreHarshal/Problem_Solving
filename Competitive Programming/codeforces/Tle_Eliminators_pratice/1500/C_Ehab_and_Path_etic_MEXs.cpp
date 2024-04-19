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
    vector<int> deg(n + 1, 0);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        deg[x]++;
        deg[y]++;
        // cout << x << " " << y << endl;
        edges.push_back({x, y});
    }
    int deg_with_3 = -1;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] >= 3)
        {
            deg_with_3 = i;
            break;
        }
    }
    int val = 0;
    // cout << deg_with_3 << endl;
    vector<int> res(n - 1, -1);
    if (deg_with_3 != -1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int x = edges[i].first;
            int y = edges[i].second;
            if (x == deg_with_3 || y == deg_with_3)
            {
                res[i] = val;
                val++;
            }
            if (val == 3)
            {
                break;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (res[i] == -1)
            {
                res[i] = val;
                val++;
            }
        }
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            res[i] = val;
            val++;
        }
    }
    for (auto i : res)
    {
        cout << i << endl;
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