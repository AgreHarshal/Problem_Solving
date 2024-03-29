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
bool dfs(int i, int p, vector<bool> &vis, vector<int> &dp, vector<vector<int>> &adj, vector<bool> &rec)
{

    if (i == vis.size() - 1)
    {
        return true;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    vis[i] = true;
    rec[i] = true;
    bool flag = false;
    for (auto k : adj[i])
    {
        if (i != p && !rec[k])
        {
            flag = flag | dfs(k, i, vis, dp, adj, rec);
        }
    }
    // cout << i << " " << flag << endl;
    rec[i] = false;
    return dp[i] = flag;
}
const int N = -1e15;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
        adj[x].push_back(y);
    }
    vector<bool> vis(n + 1, false);
    vector<bool> rec(n + 1, false);
    vector<int> dp(n + 1, -1);
    dfs(1, -1, vis, dp, adj, rec);
    vector<int> dist(n + 1, N);
    dist[1] = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int w = edges[j][2];
            int v = edges[j][1];
            if (dist[u] != N && dist[v] < dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    bool flag = false;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " " << dp[i] << endl;
    // }
    // for (int j = 0; j < m; j++)
    // {
    //     int u = edges[j][0];
    //     int w = edges[j][2];
    //     int v = edges[j][1];
    //     if (dist[u] != N && dist[v] < dist[u] + w && (dp[v] == 1 || dp[u] == 1))
    //     {
    //         dist[v] = dist[u] + w;
    //         cout << u << "-" << v << endl;
    //         flag = true;
    //         break;
    //     }
    // }

    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int w = edges[j][2];
        int v = edges[j][1];
        if (dist[u] != N && dist[v] < dist[u] + w && (dp[v] == 1 || dp[u] == 1))
        {

            dist[v] = dist[u] + w;
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << dist[n];
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