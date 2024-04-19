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
int res = 0;
int dfs(int i, int p, vector<vector<int>> &adj, vector<int> &sz)
{
    for (auto k : adj[i])
    {
        if (k != p)
        {
            int size = dfs(k, i, adj, sz);
            if (size % 2)
            {
                sz[i] += size;
            }
            else
            {
                res++;
            }
        }
    }
    return sz[i];
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    if (n % 2)
    {
        cout << "-1" << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    res = 0;
    vector<int> sz(n, 1);
    dfs(0, -1, adj, sz);
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