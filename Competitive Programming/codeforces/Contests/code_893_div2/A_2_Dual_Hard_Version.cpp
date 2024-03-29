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
    int n;
    cin >> n;
    vector<int> arr(n);
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > 0)
        {
            cnt1++;
        }
        else if (arr[i] < 0)
        {
            cnt2++;
        }
        else
        {
            cnt3++;
        }
    }
    vector<pair<int, int>> res;
    if (cnt1 + cnt3 == n)
    {
        for (int i = 1; i < n; i++)
        {
            res.push_back({i + 1, i});
        }
    }
    else if (cnt2 + cnt3 == n)
    {
        for (int i = n - 2; i >= 0; i--)
        {
            res.push_back({i + 1, i + 2});
        }
    }
    else
    {
        int pos_ind = (max_element(arr.begin(), arr.end())) - arr.begin();
        int pos_max = arr[pos_ind];
        int neg_ind = (min_element(arr.begin(), arr.end())) - arr.begin();
        int neg_max = arr[neg_ind];
        if (pos_max >= abs(neg_max))
        {
            if (cnt2 > 12)
            {
                while (neg_max > -20)
                {
                    neg_max += neg_max;
                    res.push_back({neg_ind + 1, neg_ind + 1});
                }
                for (int i = 0; i < n; i++)
                {
                    if (arr[i] > 0)
                    {
                        res.push_back({i + 1, neg_ind + 1});
                    }
                }
                for (int i = n - 2; i >= 0; i--)
                {
                    res.push_back({i + 1, i + 2});
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (arr[i] < 0)
                    {
                        res.push_back({i + 1, pos_ind + 1});
                    }
                }
                for (int i = 1; i < n; i++)
                {
                    res.push_back({i + 1, i});
                }
            }
        }
        else
        {
            if (cnt1 > 12)
            {
                int pos;
                for (int i = 0; i < n; i++)
                {
                    if (arr[i] > 0)
                    {
                        pos = i;
                        break;
                    }
                }
                for (int i = 0; i < 5; i++)
                {
                    res.push_back({pos + 1, pos + 1});
                }
                for (int i = 0; i < n; i++)
                {
                    if (arr[i] < 0)
                    {
                        res.push_back({i + 1, pos + 1});
                    }
                }
                for (int i = 1; i < n; i++)
                {
                    res.push_back({i + 1, i});
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (arr[i] > 0)
                    {
                        res.push_back({i + 1, neg_ind + 1});
                    }
                }
                for (int i = n - 2; i >= 0; i--)
                {
                    res.push_back({i + 1, i + 2});
                }
            }
        }
    }
    int t = res.size();
    cout << res.size() << endl;
    for (int i = 0; i < t; i++)
    {
        cout << res[i].first << " " << res[i].second << endl;
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