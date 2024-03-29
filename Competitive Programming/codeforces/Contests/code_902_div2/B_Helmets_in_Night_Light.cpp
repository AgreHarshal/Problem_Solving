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
    if (a.second == b.second)
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
    int n, p;
    cin >> n >> p;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), comp);
    int residents = 1;
    int i = 0;
    int cost = p;
    int first = arr[i].second;
    while (first < p && i < n && residents < n)
    {

        if (arr[i].first + residents <= n)
        {
            cost += (first * (arr[i].first));
        }
        else
        {
            cost += (first * (n - residents));
        }
        residents += arr[i].first;
        i++;
        first = arr[i].second;
    }
    if (residents < n)
    {
        cost += ((n - residents) * p);
    }
    cout << cost << endl;
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