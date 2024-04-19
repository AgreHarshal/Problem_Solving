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
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
        {
            one++;
        }
    }
    if (n <= 1 && arr[0] != 1)
    {
        cout << "-1" << endl;
    }
    else if (n == 1)
    {
        cout << "0" << endl;
    }
    else
    {
        int gc = gcd(arr[0], arr[1]);
        for (int i = 2; i < n; i++)
        {
            gc = gcd(gc, arr[i]);
        }
        if (gc != 1)
        {
            cout << "-1" << endl;
        }
        else
        {
            int res = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                int g = arr[i];
                for (int j = i + 1; j < n; j++)
                {
                    if (gcd(g, arr[j]) == 1 && j - i < res)
                    {
                        res = (j - i);
                        break;
                    }
                    else if (gcd(g, arr[j]) == 1)
                    {
                        break;
                    }
                    else
                    {
                        g = gcd(g, arr[j]);
                    }
                }
            }
            // cout << res << " ";
            res += (n - 1);
            res -= one;
            cout << res << endl;
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