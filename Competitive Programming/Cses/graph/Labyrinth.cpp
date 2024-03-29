

// for shrtest paths we dont use dfs as dfs doesnt always give minimum paths,bfs does ,so use bfs
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
// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
string ans = "";
int dfs(int v_x, int v_y, int p_x, int p_y, vector<vector<char>> &arr, int m, int n, vector<vector<int>> &dp, vector<vector<bool>> &vis)
{

    if (arr[v_x][v_y] == 'B')
    {
        return dp[v_x][v_y] = 0;
    }

    if (dp[v_x][v_y] != -1)
    {
        return dp[v_x][v_y];
    }
    vis[v_x][v_y] = true;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int mini = INT_MAX;
    for (int i = 0; i < 4; i++)
    {
        int new_x = v_x + dx[i];
        int new_y = v_y + dy[i];
        if ((new_x != p_x || new_y != p_y) && new_x < n && new_x >= 0 && new_y < m && new_y >= 0 && (arr[new_x][new_y] == '.' || arr[new_x][new_y] == 'B') && !vis[new_x][new_y])
        {
            // cout << v_x << " " << v_y << " " << new_x << " " << new_y << endl;
            int cal = dfs(new_x, new_y, v_x, v_y, arr, m, n, dp, vis);
            if (cal != INT_MAX)
            {
                mini = min(mini, 1 + cal);
            }
        }
    }
    vis[v_x][v_y] = false;
    return dp[v_x][v_y] = mini;
}
void f(int i, int j, int p_x, int p_y, vector<vector<int>> &dp, int m, int n, int res)
{
    // cout << i << " " << j << endl;

    if (dp[i][j] == 0)
    {
        return;
    }

    if (i - 1 >= 0 && i - 1 != p_x && dp[i - 1][j] != -1 && (dp[i][j] - dp[i - 1][j]) == 1)
    {
        ans += 'U';
        f(i - 1, j, i, j, dp, m, n, res);
    }
    else if (j - 1 >= 0 && j - 1 != p_y && dp[i][j - 1] != -1 && abs(dp[i][j] - dp[i][j - 1]) == 1)
    {
        ans += 'L';
        f(i, j - 1, i, j, dp, m, n, res);
    }
    else if (i + 1 < n && i + 1 != p_x && dp[i + 1][j] != -1 && (dp[i][j] - dp[i + 1][j]) == 1)
    {
        ans += 'D';
        f(i + 1, j, i, j, dp, m, n, res);
    }
    else
    {
        ans += 'R';
        f(i, j + 1, i, j, dp, m, n, res);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    string s = "";
    int final_x;
    int final_y;
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] == 'A')
            {

                res = dfs(i, j, -1, -1, arr, m, n, dp, vis);
                final_x = i;
                final_y = j;
                break;
            }
        }
    }
    if (res != INT_MAX)
    {
        cout << "YES" << endl;
        cout << res << endl;
        ans = "";
        f(final_x, final_y, -1, -1, dp, m, n, res);
        cout << ans << endl;
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