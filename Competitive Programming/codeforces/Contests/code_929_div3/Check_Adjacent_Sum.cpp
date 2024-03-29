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
void nextPermutation(vector<int> &arr)
{
    vector<int> temp(arr.size());
    int n = arr.size();
    for (int i = 0; i < arr.size(); i++)
    {
        temp[i] = arr[(i + 1) % n];
    }
    arr = temp;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    int two = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        two += (2 * arr[i]);
    }
    while (q--)
    {
        int x;
        cin >> x;

        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (two - arr[i] - arr[j] == x)
                {
                    cout << arr[i] << " ";
                    for (int k = 0; k < n; k++)
                    {
                        if (k != i && k != j)
                        {
                            cout << arr[k] << " ";
                        }
                    }
                    cout << arr[j] << endl;
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            cout << "-1" << endl;
        }
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