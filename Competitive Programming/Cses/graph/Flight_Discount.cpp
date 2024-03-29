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
#define INF 1e15
vector<int> dijikstra(int src, vector<vector<pair<int, int>>> &adj, int n)
{
    vector<int> dist(n, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, src});
    while (!q.empty())
    {
        auto p = q.top();
        int u = p.second;
        q.pop();
        int ww = p.first;
        if (dist[u] < ww)
        {
            continue;
        }
        for (auto nei : adj[u])
        {
            int v = nei.first;
            int w = nei.second;
            if (dist[u] != INF && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
    return dist;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<vector<pair<int, int>>> adj1(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj1[v].push_back({u, w});
    }
    vector<int> dist1 = dijikstra(0, adj, n);
    vector<int> dist2 = dijikstra(n - 1, adj1, n);
    int mini = INF;
    for (int i = 0; i < n; i++)
    {
        for (auto j : adj[i])
        {
            int u = i;
            int v = j.first;
            int w = j.second;
            mini = min(mini, dist1[u] + dist2[v] + w / 2);
        }
    }
    cout << mini << endl;
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