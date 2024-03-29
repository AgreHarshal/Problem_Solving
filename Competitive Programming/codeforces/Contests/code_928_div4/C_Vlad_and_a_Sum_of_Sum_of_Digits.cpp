#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int N = 200001;
vector<int> arr(N + 1, 0);
void precal()
{
    for (int i = 1; i <= N; i++)
    {
        int x = i;
        int res = 0;
        while (x != 0)
        {
            res += (x % 10);
            x /= 10;
        }
        arr[i] = res + arr[i - 1];
    }
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
    cout << arr[n] << endl;
    // int check = 0;
    // int res = 0;
    // int add = 45;
    // while (check + 10 < n)
    // {
    //     res += add;
    //     add += 10;
    //     check += 10;
    // }
    // int numbers = 0;
    // int m = check;
    // while (m != 0)
    // {
    //     numbers += (m % 10);
    //     m /= 10;
    // }
    // m = check;
    // while (m <= n)
    // {
    //     res += numbers;
    //     numbers++;
    //     m++;
    // }
    // cout << res << endl;
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