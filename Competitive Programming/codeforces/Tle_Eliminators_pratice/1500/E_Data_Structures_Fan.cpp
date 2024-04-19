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
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    string s;
    cin >> s;
    vector<int> pre(n, 0);
    int cal = 0;
    int one = 0;
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        cal = arr[i] ^ cal;
        pre[i] = cal;
        if (s[i] == '0')
        {
            zero ^= arr[i];
        }
        else
        {
            one ^= arr[i];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int check;
        cin >> check;
        if (check == 1)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int res = pre[r];
            if (l - 1 >= 0)
            {
                res ^= pre[l - 1];
            }
            one ^= res;
            zero ^= res;
        }
        else
        {
            int ip;
            cin >> ip;
            if (ip)
            {
                cout << one << " ";
            }
            else
            {
                cout << zero << " ";
            }
        }
    }
    cout << endl;
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