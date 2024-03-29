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
    string s;
    cin >> s;
    priority_queue<int> q;
    int n = s.size();
    int freq = 0;

    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
        {
            curr++;
        }
        else
        {

            q.push(curr);
            curr = 0;
        }
        if (s[i] == 'B')
        {
            freq++;
        }
    }
    if (curr != 0)
    {
        q.push(curr);
    }
    int coin = 0;
    while (freq > 0 && q.empty() == false)
    {
        int f = q.top();
        coin += f;
        freq--;
        q.pop();
    }
    cout << coin << endl;
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