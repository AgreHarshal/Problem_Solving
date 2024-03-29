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
    string s;
    cin >> s;
    if (k % 2)
    {
        string s1 = "", s2 = "";
        for (int i = 0; i < n; i += 2)
        {
            s1 += s[i];
            if (i + 1 < n)
            {
                s2 += s[i + 1];
            }
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        string res = "";
        int i = 0;
        int index = 0;
        while (index < n)
        {
            res += s1[i];
            index++;
            if (i < s2.size())
            {
                res += s2[i];
                index++;
            }
            i++;
        }
        cout << res << endl;
    }
    else
    {
        sort(s.begin(), s.end());
        cout << s << endl;
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