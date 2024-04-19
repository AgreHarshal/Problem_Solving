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
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int k = k1 + k2;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(abs(a[i] - b[i]));
    }
    while (k > 0)
    {
        int tp = pq.top();
        pq.pop();
        tp--;
        pq.push(abs(tp));

        k--;
    }
    int sum = 0;
    while (!pq.empty())
    {
        sum += (pq.top() * pq.top());
        pq.pop();
    }
    cout << sum << endl;
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
    //   int tc;
    //   cin >> tc;
    //   for (int t = 1; t <= tc; t++)
    //   {
    //       // cout << 'CASE' << t << ':' ;
    //       solve();
    //   }
    return 0;
}