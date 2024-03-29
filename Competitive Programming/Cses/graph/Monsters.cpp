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

const int N = 1e3, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
string arr[N], d[N], res = "", dir = "RDLU";
int n, m, s_x, s_y;
bool is_valid(int i, int j)
{
    if (i >= 0 && j >= 0 && i < n && j < m)
    {
        return true;
    }
    return false;
}
void solve()
{

    cin >> n >> m;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'M')
            {
                q.push({i, j});
            }
            if (arr[i][j] == 'A')
            {
                s_x = i;
                s_y = j;
            }
        }
        d[i] = string(m, 0);
    }
    q.push({s_x, s_y});
    // if (s_x == 0 || s_y == 0 || s_x == n - 1 || s_y == m - 1)
    // {
    //     cout << "YES" << endl;
    //     cout << "0" << endl;
    //     return;
    // }
    bool possible = false;
    while (!q.empty())
    {
        auto p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        // if (arr[x][y] == 'M' && (x == 0 || y == 0 || x == n - 1 || y == m - 1))
        // {
        //     possible = false;
        //     break;
        // }
        if (arr[x][y] == 'A' && (x == 0 || y == 0 || x == n - 1 || y == m - 1))
        {
            possible = true;
            while (1)
            {
                res.push_back(d[x][y]);
                char pre = d[x][y];
                cout << pre << endl;
                if (pre == 'U')
                {
                    x++;
                }
                else if (pre == 'D')
                {
                    x--;
                }
                else if (pre == 'R')
                {
                    y--;
                }
                else if (pre == 'L')
                {
                    y++;
                }
                if (x == s_x && y == s_y)
                {
                    break;
                }
            }
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (is_valid(new_x, new_y) && arr[new_x][new_y] == '.')
            {
                arr[new_x][new_y] = arr[x][y];
                d[new_x][new_y] = dir[i];
                q.push({new_x, new_y});
            }
        }
    }
    if (possible)
    {
        cout << "YES" << endl;
        reverse(res.begin(), res.end());
        cout << res.size() << endl;
        cout << res << endl;
    }
    else
    {
        cout << "NO" << endl;
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