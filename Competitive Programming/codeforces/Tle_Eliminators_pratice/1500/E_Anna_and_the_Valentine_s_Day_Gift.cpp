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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int digits = 0;
    vector<int> aez;
    for (int i = 0; i < n; i++)
    {
        int k = arr[i];
        int add = 0;
        int zeros = 0;

        bool flag = true;
        while (k != 0)
        {
            if (k % 10 == 0 && flag)
            {
                zeros++;
            }
            else
            {
                flag = false;
            }
            k /= 10;
            add++;
        }
        if (zeros > 0)
        {
            aez.push_back(zeros);
        }
        digits += add;
    }
    sort(aez.begin(), aez.end(), greater<int>());
    int sub = 0;
    for (int i = 0; i < aez.size(); i++)
    {
        if (i % 2 == 0)
        {
            sub += aez[i];
        }
    }
    // cout << digits << " " << endl;
    if (digits - sub > m)
    {
        cout << "Sasha" << endl;
    }
    else
    {
        cout << "Anna" << endl;
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