#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define INF 1e15
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
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        dist[x][y] = min(dist[x][y], z);
        dist[y][x] = min(dist[x][y], z);
    }
    for (int i = 0; i < n; i++)
    {
        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < n; b++)
            {
                if (dist[a][i] != INF && dist[i][b] != INF && dist[a][b] > dist[a][i] + dist[i][b])
                {
                    dist[a][b] = dist[a][i] + dist[i][b];
                }
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << (dist[a][b] != INF ? dist[a][b] : -1) << endl;
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