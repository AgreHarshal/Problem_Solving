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
    //   int n;
    //   cin>>n;
    //   vector<int>arr(n);
    //   for(int i=0;i<n;i++){
    //     cin>>arr[i];
    //   }
    string s;
    cin >> s;
    int n = s.size();
    int mul = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            sum++;
            sum %= mod;
        }
        else if (s[i] == 'b')
        {
            mul *= (sum + 1);
            mul %= mod;
            sum = 0;
        }
    }
    mul *= (sum + 1);
    mul %= mod;
    cout << mul - 1 << endl;
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