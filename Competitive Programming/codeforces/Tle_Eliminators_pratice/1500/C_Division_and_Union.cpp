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
bool comp(vector<int> &arr1, vector<int> &arr2)
{
    return arr1[2] < arr2[2];
}
void solved()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i].push_back(min(x, y));
        arr[i].push_back(max(x, y));
        arr[i].push_back(i);
        arr[i].push_back(0);
        cout << x << " " << y << " ";
    }

    // sort(arr.begin(), arr.end());
    // int i = 1;
    // bool flag = false;
    // int last = 0;
    // arr[0][3] = 1;
    // while (i < n)
    // {
    //     if (!flag)
    //     {
    //         if (arr[i][0] <= arr[last][1])
    //         {
    //             arr[i][3] = 1;
    //             last = i;
    //         }
    //         else
    //         {
    //             arr[i][3] = 2;
    //             flag = true;
    //         }
    //     }
    //     else
    //     {
    //         arr[i][3] = 2;
    //     }
    //     i++;
    // }
    // if (!flag)
    // {
    //     cout << "-1" << endl;
    //     return;
    // }
    // sort(arr.begin(), arr.end(), comp);
    // for (auto i : arr)
    // {
    //     cout << i[3] << " ";
    // }
    // cout << endl;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i].push_back(min(x, y));
        arr[i].push_back(max(x, y));
        arr[i].push_back(i);
        arr[i].push_back(0);
    }
    sort(arr.begin(), arr.end());

    int l = 0, r = -1;
    int k = 1;
    arr[0][3] = 1;
    while (k < n)
    {
        if (r != -1 && arr[k][0] <= arr[l][1] && arr[k][0] <= arr[r][1])
        {
            cout << "-1" << endl;
            return;
        }
        else if (arr[k][0] <= arr[l][1])
        {
            if (arr[k][1] > arr[l][1])
            {
                l = k;
            }

            arr[k][3] = 1;
        }
        else if (r != -1 && arr[k][0] <= arr[r][1])
        {

            if (arr[k][1] > arr[r][1])
            {
                r = k;
            }
            arr[k][3] = 2;
        }
        else
        {
            if (r == -1)
            {
                r = k;
            }
            if (arr[k][1] > arr[r][1])
            {
                r = k;
            }

            arr[k][3] = 2;
        }
        k++;
    }
    if (r == -1)
    {
        cout << "-1" << endl;
        return;
    }
    sort(arr.begin(), arr.end(), comp);
    for (auto i : arr)
    {
        cout << i[3] << " ";
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