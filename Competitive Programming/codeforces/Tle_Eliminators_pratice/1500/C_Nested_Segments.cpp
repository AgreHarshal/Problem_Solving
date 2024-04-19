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
// bool compareFirst(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs)
// {
//     if (lhs.first != rhs.first)
//     {
//         return lhs.first < rhs.first;
//     }
//     else
//     {
//         return lhs.second > rhs.second;
//     }
// }
bool compare(pair<pair<int, int>, int> &lhs, pair<pair<int, int>, int> &rhs)
{
    if (lhs.first.first != rhs.first.first)
    {
        return lhs.first.first < rhs.first.first;
    }
    else if (lhs.first.second != rhs.first.second)
    {
        return lhs.first.second > rhs.first.second;
    }
    else
    {
        return lhs.second > rhs.second;
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> arr(n);
    multiset<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        arr[i].first.first = l;
        arr[i].first.second = r;
        arr[i].second = i;
        s.insert({r, i});
    }
    sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < n; i++)
    {
        auto it = s.upper_bound(make_pair(arr[i].first.second, n));

        --it;
        // cout << it->first << endl;
        if (it != s.begin())
        {
            if (it->second != arr[i].second)
            {
                cout << it->second + 1 << " " << arr[i].second + 1 << endl;
            }
            else
            {
                --it;
                cout << it->second + 1 << " " << arr[i].second + 1 << endl;
            }
            // cout << it->first << endl;

            return;
        }
        else
        {
            s.erase(it);
        }
    }
    cout << "-1 -1" << endl;
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