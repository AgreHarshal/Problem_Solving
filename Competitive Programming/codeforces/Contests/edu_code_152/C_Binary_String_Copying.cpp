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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<int> lf(n), rf(n);
    lf[0] = -1;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            lf[i] = lf[i - 1];
        }
        if (s[i] == '0')
        {
            lf[i] = i;
        }
    }
    rf[n - 1] = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i + 1 < n)
        {
            rf[i] = rf[i + 1];
        }
        if (s[i] == '1')
        {
            rf[i] = i;
        }
    }

    set<pair<int, int>> st;
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;

        int fir_first = rf[l - 1];
        int fir_zero = lf[r - 1];
        if (fir_first < fir_zero)
        {
            st.insert({fir_first, fir_zero});
        }
        else
        {
            st.insert({-1, -1});
        }
    }
    cout << st.size() << endl;
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