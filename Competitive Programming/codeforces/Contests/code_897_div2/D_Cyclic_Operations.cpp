#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
class DSU
{
public:
    vector<int> parent;
    vector<int> rank;
    int N;

    DSU(int n)
    {
        N = n;
        parent = vector<int>(n + 1, 0);
        rank = vector<int>(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    vector<int> retp()
    {
        return parent;
    }
    int findparent(int u)
    {

        if (u != parent[u])
        {
            return parent[u] = findparent(parent[u]);
        }
        else
        {
            return parent[u];
        }
    }
    void union1(int u, int v)
    {
        int x = findparent(u);
        int y = findparent(v);
        if (x != y)
        {
            int r1 = rank[x];
            int r2 = rank[y];
            if (r1 >= r2)
            {
                parent[y] = x;
                rank[x] = rank[x] + rank[y];
            }
            else
            {
                parent[x] = y;
                rank[y] += rank[x];
            }
        }
    }
};
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
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (k == 1)
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
        {
            cout << "NO" << endl;
            return;
        }
    }
    else
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == i + 1)
            {
                cnt++;
            }
            if (cnt > 0)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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