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
const int N = 1e5 + 1;
vector<vector<int>> adj(N);
vector<int> ne(N, -1);
int n, m;
bool flag = false;
void dfs(int i, int p, vector<bool> &vis, int mark)
{
    // cout << i << " " << mark << endl;
    ne[i] = mark;
    if (flag)
    {
        return;
    }
    vis[i] = true;
    for (auto k : adj[i])
    {
        if (k != p && vis[k] && ne[k] == ne[i])
        {
            flag = true;
            return;
        }
        else if (k != p && !vis[k])
        {
            dfs(k, i, vis, (!mark));
        }
    }
}
void solve()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {

        if (!vis[i])
        {
            // cout << i << endl;
            dfs(i, -1, vis, 1);
        }
    }
    if (flag)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (ne[i] == 0)
            {
                cout << "2 ";
            }
            else
            {
                cout << ne[i] << " ";
            }
        }
        cout << endl;
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