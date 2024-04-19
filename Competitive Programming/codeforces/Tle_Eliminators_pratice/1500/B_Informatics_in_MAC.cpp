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
    bool is_zero = false;
    vector<int> freq(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            is_zero = true;
        }
        freq[arr[i]]++;
    }
    if (!is_zero)
    {
        cout << n << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << i << " " << i << endl;
        }
    }
    else

    {
        bool possible = true;
        int fr = freq[0];
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            if (freq[i] != fr && freq[i] != 0)
            {
                possible = false;
                break;
            }
            else if (freq[i] != fr && freq[i] == 0)
            {
                res = i;
                break;
            }
        }

        if (!possible)
        {
            cout << "-1" << endl;
        }
        else
        {
            int i = 0;
            int add = 0;
            int r1, l2, r2;
            int comp = (res - 1) * (res) / 2;
            cout << comp << " " << res << endl;
            while (i < n)
            {
                cout << i << endl;
                if (arr[i] < res)
                {
                    add += arr[i];
                }

                if (comp != 0 && (add % comp) == 0)
                {
                    r1 = i;
                    l2 = i + 1;
                    cout << "bruhh" << endl;
                    break;
                }
                i++;
            }
            i++;
            add = 0;

            while (i < n)
            {
                if (arr[i] < res)
                {
                    add += arr[i];
                }
                i++;
            }
            if (add % comp == 0)
            {
                cout << "2" << endl;
                cout << "1 " << r1 << endl;
                cout << r1 + 1 << " " << n << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
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