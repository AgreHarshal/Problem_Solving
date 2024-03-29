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
void solve()
{
    int n, a, q;
    cin >> n >> a >> q;
    vector<char> arr(q);
    for (int i = 0; i < q; i++)
    {
        cin >> arr[i];
    }
    int curr = a, max = a;
    int plus = a;
    for (int i = 0; i < q; i++)
    {
        if (arr[i] == '+')
        {
            plus++;
            curr++;
        }
        else
        {
            curr--;
        }
        if (curr > max)
        {
            max = curr;
        }
    }
    if (max >= n)
    {
        cout << "YES" << endl;
    }
    else if (plus >= n)
    {
        cout << "MAYBE" << endl;
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