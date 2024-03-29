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
int start_node = -1;
bool found = false;
void dfs(int v, int p, vector<vector<int>> &adj, vector<bool> &vis)
{

    if (found == true)
    {
        return;
    }
    vis[v] = true;
    for (auto i : adj[v])
    {
        if (i != p && vis[i] == true)
        {
            if (found == true)
            {
                return;
            }

            start_node = i;
            found = true;
            return;
        }
        else if (i != p && vis[i] == false)
        {
            dfs(i, v, adj, vis);
        }
    }
}
int dfs1(int v, int p, vector<vector<int>> &adj, vector<bool> &vis)
{
    if (v == start_node)
    {
        return 0;
    }
    vis[v] = true;
    int ans = INT_MAX;
    for (auto i : adj[v])
    {

        if (i != p && vis[i] == false)
        {

            ans = min(ans, 1 + dfs1(i, v, adj, vis));
        }
    }
    return ans;
}
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(n + 1, false);
    vector<bool> vis1(n + 1, false);
    if (a == b)
    {
        cout << "NO" << endl;
        return;
    }
    start_node = -1;
    found = false;
    dfs(b, -1, adj, vis);
    vis = vis1;
    int dis_a = dfs1(a, -1, adj, vis);
    vis = vis1;
    int dis_b = dfs1(b, -1, adj, vis);
    if (dis_a <= dis_b)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    return;
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