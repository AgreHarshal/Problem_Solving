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
int final;
bool rep = false;
bool dfs(int i, int p, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &par)
{
    if (rep)
    {
        return true;
    }
    vis[i] = true;
    bool flag = false;
    for (int k = 0; k < adj[i].size(); k++)
    {
        if (rep)
        {
            return true;
        }
        if (adj[i][k] != p && !vis[adj[i][k]])
        {
            par[adj[i][k]] = i;
            flag = flag | dfs(adj[i][k], i, adj, vis, par);
        }
        else if (adj[i][k] != p && vis[adj[i][k]])
        {
            par[adj[i][k]] = i;
            final = adj[i][k];
            vector<int> ans;
            int start = final;
            int j = par[start];
            ans.push_back(start);
            while (j != start)
            {
                ans.push_back(j);
                j = par[j];
            }
            ans.push_back(start);

            cout << ans.size() << endl;
            for (auto p : ans)
            {
                cout << p << " ";
            }
            cout << endl;
            exit(0);
            break;
            return true;
        }
    }
    return flag;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        // cout << x << " " << y << endl;
    }

    vector<int> par(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 0; i <= n; i++)
    {
        par[i] = i;
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, adj, vis, par);
        }
    }
    if (ans.size() > 0)
    {
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
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