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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> a;
    vector<int> b;
    a.push_back(arr[0]);
    int i = 0;
    while (i + 1 < n && arr[i + 1] <= arr[i])
    {
        a.push_back(arr[i + 1]);
        i++;
    }
    if (i + 1 < n)
    {
        b.push_back(arr[i + 1]);
    }

    int j = 0;
    int k = i + 2;
    int res = 0;
    // cout << i << " " << j << " " << k << endl;
    while (k < n)
    {
        if (arr[k] <= a[i] && arr[k] <= b[j])
        {
            if (a[i] < b[j])
            {
                a.push_back(arr[k]);
                k++;
                i++;
            }
            else
            {
                b.push_back(arr[k]);
                k++;
                j++;
            }
        }
        else if (arr[k] <= a[i])
        {
            a.push_back(arr[k]);
            k++;
            i++;
        }
        else if (arr[k] <= b[j])
        {
            b.push_back(arr[k]);
            k++;
            j++;
        }
        else
        {
            res++;
            if (a[i] > b[j])
            {
                b.push_back(arr[k]);
                k++;
                j++;
            }
            else
            {

                a.push_back(arr[k]);
                k++;
                i++;
            }
            // cout << arr[k] << " " << res << endl;
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
        // cout << "CASE" << t << ':';
        solve();
    }
    return 0;
}