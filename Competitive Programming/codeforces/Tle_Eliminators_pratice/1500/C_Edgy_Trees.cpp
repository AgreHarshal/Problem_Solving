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

const int N = 3e5 + 9;
struct DSU
{
    vector<int> par, rnk, sz;
    int c;
    DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n)
    {
        for (int i = 1; i <= n; ++i)
            par[i] = i;
    }
    int find_par(int i)
    {
        return (par[i] == i ? i : (par[i] = find_par(par[i])));
    }
    bool same(int i, int j)
    {
        return find_par(i) == find_par(j);
    }
    int get_size(int i)
    {
        return sz[find_par(i)];
    }
    int count()
    {
        return c; // connected components
    }
    int union_(int i, int j)
    {
        if ((i = find_par(i)) == (j = find_par(j)))
            return -1;
        else
            --c;
        if (rnk[i] > rnk[j])
            swap(i, j);
        par[i] = j;
        sz[j] += sz[i];
        if (rnk[i] == rnk[j])
            rnk[j]++;
        return j;
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    DSU dsu(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0)
        {
            dsu.union_(x, y);
        }
    }
    int res = 1;
    for (int i = 0; i < k; i++)
    {
        res *= n;
        res %= mod;
    }
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[dsu.find_par(i)])
        {
            int sz = dsu.get_size(i);
            vis[dsu.find_par(i)] = true;
            int cal = 1;
            for (int i = 0; i < k; i++)
            {
                cal *= sz;
                cal %= mod;
            }
            res = (res - cal + mod) % mod;
        }
    }
    cout << res << endl;
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