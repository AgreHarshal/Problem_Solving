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
bool issquare(vector<vector<char>> &arr, int i, int j, int n)
{
    int k = j;
    while (j < n && arr[i][j] != '0')
    {
        j++;
    }
    j--;
    if (j == k)
    {
        if (i + 1 < n && arr[i + 1][j] == '0' || i + 1 == n)
        {
            return true;
        }
    }
    else
    {
        if (i + 1 < n && arr[i + 1][j] == '1')
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '1')
            {
                if (issquare(arr, i, j, n))
                {
                    cout << "SQUARE" << endl;
                }
                else
                {
                    cout << "TRIANGLE" << endl;
                }
                return;
            }
        }
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