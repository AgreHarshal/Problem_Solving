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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> tp(n, 0);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l;
        tp[l]++;
        if (r < n)
        {
            tp[r]--;
        }
    }
    for (int i = 1; i < n; i++)
    {
        tp[i] += tp[i - 1];
    }
    sort(tp.begin(), tp.end());
    sort(arr.begin(), arr.end());
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += (arr[i] * tp[i]);
    }
    cout << sum << endl;
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