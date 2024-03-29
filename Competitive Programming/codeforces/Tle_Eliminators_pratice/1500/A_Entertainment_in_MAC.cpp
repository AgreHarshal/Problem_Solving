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
    string s;
    cin >> s;
    int i = 0, j = s.size() - 1;
    while (i < j && s[i] == s[j])
    {
        i++;
        j--;
    }

    if (s[i] > s[j])
    {
        reverse(s.begin(), s.end());
        n--;
    }
    if (n % 2)
    {
        string temp = s;
        reverse(temp.begin(), temp.end());
        s += temp;
        cout << s << endl;
    }
    else
    {
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