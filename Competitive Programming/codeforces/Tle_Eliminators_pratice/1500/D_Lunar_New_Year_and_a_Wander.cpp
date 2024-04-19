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
vector<int> res;
void bfs(int i, int p, vector<bool> &vis, vector<vector<int>> &adj)
{
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(1);

    vis[1] = true;
    while (!q.empty())
    {
        int pp = q.top();
        q.pop();
        cout << pp << " ";

        vis[pp] = true;
        for (auto j : adj[pp])
        {
            if (!vis[j])
            {
                q.push((j));
                vis[j] = true;
            }
        }
    }
    cout << endl;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n + 1, false);
    bfs(1, -1, vis, adj);
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
    //   int tc;
    //   cin >> tc;
    //   for (int t = 1; t <= tc; t++)
    //   {
    //       // cout << 'CASE' << t << ':' ;
    //       solve();
    //   }
    return 0;
}