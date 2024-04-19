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
    vector<int> tea(n);
    vector<int> taste(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tea[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> taste[i];
    }
    vector<int> pre(n, 0);
    pre[0] = taste[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + taste[i];
    }
    vector<int> freq(n + 1, 0);
    vector<int> res(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int addition = 0;
        if (i - 1 >= 0)
        {
            addition += pre[i - 1];
        }
        auto it = lower_bound(pre.begin(), pre.end(), tea[i] + addition);
        int index = it - pre.begin();

        if (index - 1 >= 0)
        {
            // cout << tea[i] << " " << index << " ";
            freq[index - 1]++;
            int add = 0;
            if (i - 1 >= 0)
            {
                add = (tea[i] - pre[index - 1] + pre[i - 1]);
            }
            else
            {
                add = (tea[i] - pre[index - 1]);
            }
            // cout << add << endl;
            res[index] += add;
            if (i - 1 >= 0)
            {
                freq[i - 1]--;
            }
        }
        else
        {
            res[index] += tea[i];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        freq[i] += freq[i + 1];
    }
    // cout << "freq" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << freq[i] << " ";
    // }
    // cout << "freq_ended" << endl;
    for (int i = 0; i < n; i++)
    {
        res[i] += (freq[i] * taste[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
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