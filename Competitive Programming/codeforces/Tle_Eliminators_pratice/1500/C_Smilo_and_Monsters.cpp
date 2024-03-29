
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
    int i = 0, j = n - 1;
    int res = 0;
    int add = 0;
    bool used = true;
    while (i < j)
    {
        while (i < j && add + arr[i] < arr[j])
        {
            add += arr[i];
            res += arr[i];
            i++;
            // cout << add << " " << i << " " << (arr[i] + add) << " " << arr[j] << endl;
        }
        // cout << i << " " << j << endl;
        used = false;
        if (i < j)
        {
            add = arr[j] - add;
            res += add;
            add = arr[i] - add;
            res++;
            j--;
            i++;
            used = true;
        }
    }
    if (used && add)
    {
        res += ((add / 2) + 1 + add % 2);
    }
    else if (i == j)
    {
        if (arr[i] == 1 && add == 0)
        {
            res++;
        }
        else
        {
            res += ((arr[j] - add) / 2 + (arr[j] - add) % 2 + 1);
        }
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