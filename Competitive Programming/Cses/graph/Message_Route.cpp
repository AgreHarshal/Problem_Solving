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
int n, m;

void solve()
{
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> res(n + 1);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        res[i] = i;
    }
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        if (p == n)
        {
            while (1)
            {
                ans.push_back(p);
                if (p == 1)
                {
                    break;
                }
                p = res[p];
            }
            break;
        }
        for (auto i : adj[p])
        {
            if (res[i] == i && i != 1)
            {
                q.push(i);
                res[i] = p;
            }
        }
    }
    if (res[n] == n)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
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