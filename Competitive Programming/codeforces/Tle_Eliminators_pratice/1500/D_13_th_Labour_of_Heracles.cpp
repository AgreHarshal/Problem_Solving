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
    vector<int> arr(n + 1);
    int sum = 0;
    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        deg[x]++;
        deg[y]++;
    }
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++)
    {
        while (--deg[i])
        {
            pq.push(arr[i]);
        }
    }

    cout << sum << " ";
    for (int i = 0; i < n - 2; i++)
    {
        sum += (pq.top());
        pq.pop();
        cout << sum << " ";
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