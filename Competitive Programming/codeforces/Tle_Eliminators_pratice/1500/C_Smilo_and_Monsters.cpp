
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

void precal() {}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
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

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int i = 0;
    int sum = 0;
    int j = n - 1;
    int res = 0;

    while (i <= j)
    {
        sum += arr[i];
        if (i < j && sum >= arr[j])
        {
            res += (arr[j] + 1);
            sum -= arr[j];
            j--;
        }
        i++;
    }
    res += ((sum + 1) / 2 + (sum > 1));
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