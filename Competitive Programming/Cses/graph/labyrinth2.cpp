// it was giving error when i accessed the d[0][999] without d[i]=string(n,0) ,see whyy is that

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

const int n_m = 1e3, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
string s[n_m], d[n_m], dir = "RDLU", res = "";
int s_x, s_y, d_x, d_y, n, m;
bool is_valid(int i, int j)
{
    // cout << (i >= 0) << " " << (i < n) << " " << (j >= 0) << " " << (j < m) << " " << n << " " << m << endl;
    if (i >= 0 && i < n && j >= 0 && j < m)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve()
{
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'A')
            {
                s_x = i, s_y = j;
            }
            if (s[i][j] == 'B')
            {
                d_x = i, d_y = j;
            }
        }
        // d[i] = string(m, 0);
    }
    queue<pair<int, int>> q;
    q.push({s_x, s_y});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        // cout << x << " " << y << endl;
        // cout << x << " " << y << endl;
        if (x == d_x && y == d_y)
        {
            // cout << "blashh" << endl;
            while (1)
            {
                res.push_back(d[x][y]);
                // cout << x << " " << y << endl;
                if (d[x][y] == 'U')
                {
                    x++;
                }
                else if (d[x][y] == 'R')
                {
                    y--;
                }
                else if (d[x][y] == 'L')
                {
                    y++;
                }
                else if (d[x][y] == 'D')
                {
                    x--;
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

            // cout << new_x << " " << new_y << " " << (s[new_x][new_y] == '.') << " " << endl;
            if (is_valid(new_x, new_y) && (s[new_x][new_y] == '.' || s[new_x][new_y] == 'B'))
            {
                // cout << "ghus" << endl;

                s[new_x][new_y] = '#';
                d[new_x][new_y] = dir[i];
                q.push({new_x, new_y});
            }
            // cout << endl;
        }
    }
    if (s[d_x][d_y] == 'B')
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << res.size() << endl;
        reverse(res.begin(), res.end());
        for (auto i : res)
        {
            cout << i;
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
    // precal();
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