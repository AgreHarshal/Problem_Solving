
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
#define int long long
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

    int myunion(int i, int j)
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
    vector<int> parr()
    {
        return par;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    // cout << "blassh" << endl;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        dsu.myunion(x, y);
    }
    vector<int> parrr = dsu.parr();
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << parrr[i] << " ";
        cout << dsu.find_par(i) << endl;
    }
    map<int, int> mp;
    vector<int> par = dsu.parr();
    for (int i = 1; i < par.size(); i++)
    {
        mp[par[i]]++;
    }
    vector<pair<int, int>> res;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (i == mp.begin())
        {
            continue;
        }
        res.push_back({(mp.begin())->first, (i)->first});
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].first << " " << res[i].second << endl;
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