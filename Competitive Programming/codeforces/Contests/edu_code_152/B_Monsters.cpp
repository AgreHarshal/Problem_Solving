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
bool comp(pair<int, int> &a, pair<int, int> &b)
{

    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second < b.second;
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int o = x % k;
        if (o == 0)
        {
            res.push_back(i + 1);
        }
        else
        {
            arr.push_back({o, i + 1});
        }
    }
    sort(arr.begin(), arr.end(), comp);
    for (auto i : res)
    {
        cout << i << " ";
    }
    for (auto i : arr)
    {
        cout << i.second << " ";
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