// Very important question,why we need N times backtracking..
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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> dp(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    // cout << "blashh" << endl;
    vector<int> dist(n + 1, INF);
    bool flag = false;
    dist[1] = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (auto k : adj[j])
            {
                int v = k.first;
                int w = k.second;

                // cout << j << " " << v << " " << w << " " << dist[j] + w << " " << dist[v] << endl;
                if (dist[j] + w < dist[v])
                {
                    dp[v] = j;
                    dist[v] = w + dist[j];
                    if (i == n)
                    {
                        flag = true;
                        cout << "YES" << endl;

                        for (int i = 1; i <= n; i++)
                        {
                            // cout << v << endl;
                            v = dp[v];
                        }
                        vector<int> res;
                        res.push_back(v);
                        // res.push_back(j);
                        int p = v;
                        v = dp[v];
                        while (p != v)
                        {
                            // cout << p << " " << dp[p] << endl;
                            // cout << p << " ";
                            res.push_back(v);
                            v = dp[v];
                        }
                        res.push_back(v);
                        for (int xy = res.size() - 1; xy >= 0; xy--)
                        {
                            cout << res[xy] << " ";
                        }
                        // cout << v << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
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