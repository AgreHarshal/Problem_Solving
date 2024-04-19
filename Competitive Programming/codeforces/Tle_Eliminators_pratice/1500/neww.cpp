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
    int x, n;
    cin >> n >> x;
    vector<int> bit(33, 0);
    for (int i = 0; i <= 32; i++)
    {
        if (n & (1 << i))
        {
            bit[i] = 1;
        }
    }
    --x;
    vector<int> bit_x(33, 0);
    int max_bit = 0;
    for (int i = 0; i <= 32; i++)
    {
        if (x & (1 << i))
        {
            max_bit = i;
            bit_x[i] = 1;
        }
    }
    int i = 0;
    int j = 0;

    while (i <= max_bit)
    {

        while (j <= 32 && bit[j] != 0)
        {
            j++;
        }
        bit[j] = bit_x[i];
        i++;
        j++;
    }
    int res = 0;
    for (int i = 0; i <= 32; i++)
    {
        if (bit[i])
        {
            res = res | (1 << i);
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