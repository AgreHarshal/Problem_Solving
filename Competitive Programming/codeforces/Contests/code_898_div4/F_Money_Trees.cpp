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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int low = n - 2;
    int high = n - 1;
    int res = 0;
    int max_res = INT_MIN;
    int min_val = *(min_element(a.begin(), a.end()));
    if (min_val > k)
    {
        max_res = 0;
        cout << "0" << endl;
        return;
    }
    else
    {
        max_res = 1;
    }

    int apple = 0;
    apple += a[n - 1];
    for (int i = n - 1; i >= 1; i--)
    {
        if (h[i - 1] % h[i] == 0)
        {
            apple += (a[i - 1]);
            if (apple > k)
            {
                apple -= (a[high]);
                high--;
            }
            res = high - (i - 1) + 1;
        }
        else
        {
            high = i - 1;
            apple = a[high];
        }
        if (res > max_res)
        {
            max_res = res;
        }
    }
    cout << max_res << endl;
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