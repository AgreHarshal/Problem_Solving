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
    string s;
    cin >> s;
    string hr = "", min = "";
    int n = s.size();
    int i = 0;
    while (s[i] != ':')
    {
        hr += s[i];
        i++;
    }
    i++;
    while (i < n)
    {
        min += s[i];
        i++;
    }
    int hour = stoi(hr);

    int minute = stoi(min);
    if (hour >= 1 && hour < 12)
    {

        if (hour < 10)
        {
            cout << "0" << hour << ":" << min << " AM" << endl;
        }
        else
        {
            cout << hour << ":" << min << " AM" << endl;
        }
    }
    else if (hour >= 13)
    {
        hour %= 12;
        if (hour >= 10)
        {
            cout << hour << ":" << min << " PM" << endl;
        }
        else
        {
            cout << "0" << hour << ":" << min << " PM" << endl;
        }
    }
    else
    {
        if (hour < 1)
        {
            cout << "12"
                 << ":" << min << " AM" << endl;
        }
        else
        {
            cout << "12"
                 << ":" << min << " PM" << endl;
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