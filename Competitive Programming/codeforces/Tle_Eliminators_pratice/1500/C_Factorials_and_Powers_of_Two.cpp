#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int N;
vector<int> dp = {
    1LL, 2LL, 6LL, 24LL, 120LL, 720LL, 5040LL, 40320LL,
    362880LL, 3628800LL, 39916800LL, 479001600LL, 6227020800LL,
    87178291200LL, 1307674368000LL};
vector<int> subsets;
unordered_map<int, int> mp;
void precal()
{
    N = dp.size();
    int loop = (1 << N);

    for (int i = 0; i < loop; i++)
    {
        int res = 0;
        int bits = 0;
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                // cout << i << " -" << j << " " << dp[j] << endl;
                bits++;
                res += dp[j];
            }
        }
        mp[res] = bits;
        subsets.push_back(res);
        // cout << bits << " " << i << " " << res << endl;
    }
}
int popcount(unsigned long long n)
{
    int count = 0;
    while (n)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

void solve()
{
    int n;
    cin >> n;
    unsigned int f = n;
    int res = popcount(f);
    // cout << res << endl;
    for (int i = 0; i < subsets.size(); i++)
    {
        if (subsets[i] > n)
        {
            break;
        }
        int temp = n;
        temp -= subsets[i];
        int cal = mp[subsets[i]];
        cal += (popcount(temp));
        // cout << cal << " " << res << endl;
        res = min(res, cal);
    }
    cout << res << endl;
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