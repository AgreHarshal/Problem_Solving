#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int search(vector<int> &nums, int target, bool findStartIndex)
{
    int answer = -1;
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target < nums[mid])
        {
            end = mid - 1;
        }
        else if (target > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            answer = mid;
            if (findStartIndex)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    return answer;
}

int countOccurrences(vector<int> &nums, int x)
{
    int firstIndex = search(nums, x, true);
    int lastIndex = search(nums, x, false);
    if (firstIndex != -1 && lastIndex != -1)
        return lastIndex - firstIndex + 1;
    else
        return 0;
}
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
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;

        int ro = x * x - 4 * y;

        if (ro >= 0)
        {
            int s = ro;
            ro = sqrt(ro);

            if (ro * ro == s)
            {
                int a = (ro + x) / 2;
                int b = (x - ro) / 2;

                if (a == b)
                {
                    int freq = countOccurrences(arr, a);
                    int res = freq * (freq - 1) / 2;
                    cout << res << " ";
                }
                else
                {
                    int freq1 = countOccurrences(arr, a);
                    int freq2 = countOccurrences(arr, b);

                    int res = freq1 * freq2;
                    cout << res << " ";
                }
            }
            else
            {
                cout << "0"
                     << " ";
            }
        }
        else
        {
            cout << "0"
                 << " " << endl;
        }
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