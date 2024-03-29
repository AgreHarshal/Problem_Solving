#include <iostream>
#include <vector>
#include <limits>
#include <bits/stdc++.h> // Include the limits header for numeric_limits
using namespace std;

const int INF = numeric_limits<int>::max(); // Define INF as the maximum value for int

void printNegativeCycle(vector<int> &dp, int u, int v)
{
    vector<int> res;
    res.push_back(v);
    res.push_back(u);
    cout << "YES" << endl;
    cout << v << " " << u << " ";
    int p = dp[u];
    while (p != v)
    {
        res.push_back(p);
        p = dp[p];
    }
    res.push_back(v);
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

void shortestPath(vector<vector<pair<int, int>>> &adj, int n, int m)
{
    vector<int> dist(n + 1, INF);
    vector<int> dp(n + 1, -1);
    dist[1] = 0;

    for (int i = 0; i < 3 * m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (auto k : adj[j])
            {
                int v = k.first;
                int w = k.second;
                if (dist[j] != INF && dist[j] + w < dist[v])
                {
                    dist[v] = w + dist[j];
                    dp[v] = j;
                    if (i > m - 1)
                    { // Check for negative cycle after m iterations
                        printNegativeCycle(dp, j, v);
                        return;
                    }
                }
            }
        }
    }

    cout << "NO" << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    shortestPath(adj, n, m);

    return 0;
}
