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
// void f(int i, int j, bool down, string temp, vector<string> &arr, string &res, int &cnt)
// {
//     if (i >= 2 || j >= arr[0].size())
//     {
//         return;
//     }
//     if (i == 1 && j == arr[0].size() - 1)

//     {
//         if (res == "-1")
//         {
//             res = temp;
//         }
//         else if (temp < res)
//         {
//             res = temp;
//             cnt = 1;
//         }
//         else if (temp == res)
//         {
//             cnt++;
//         }
//     }
//     if (down)
//     {
//         temp.push_back(arr[i][j + 1]);
//         f(i, j + 1, down, temp, arr, res, cnt);
//         temp.pop_back();
//     }
//     else
//     {

//         temp.push_back(arr[i][j + 1]);
//         f(i, j + 1, down, temp, arr, res, cnt);
//         temp.pop_back();
//         down = true;
//         temp.push_back(arr[i + 1][j]);
//         f(i + 1, j, down, temp, arr, res, cnt);
//         temp.pop_back();
//     }
// }
void solve()
{
    int n;
    cin >> n;
    vector<string> arr(2);
    cin >> arr[0];
    cin >> arr[1];
    string res = "";
    res += arr[0][0];
    int cnt = 1;
    int i = 0;
    int j = 0;
    for (j = 1; j < n; j++)
    {
        if (arr[i][j] == arr[i + 1][j - 1])
        {
            res += arr[i][j];
        }
        else if (arr[i][j] < arr[i + 1][j - 1])
        {
            res += arr[i][j];
        }
        else
        {
            res += arr[i + 1][j - 1];
            j++;
            while (j <= n)
            {
                res += arr[i + 1][j - 1];
                j++;
            }
            break;
        }
    }
    if (res.size() != n + 1)
    {
        res += arr[1][n - 1];
    }
    i = res.size() - 1;
    j = n - 1;
    while (i >= 0 and j >= 0 and res[i] == arr[1][j])
    {
        i--;
        j--;
    }
    for (int i = j + 1; i < n - 1; i++)
    {
        if (arr[0][i + 1] == arr[1][i])
        {
            cnt++;
        }
        else
        {
            break;
        }
    }
    cout << res << endl
         << cnt << endl;
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