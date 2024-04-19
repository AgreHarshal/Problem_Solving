#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
void precal()
{
}

int seg[4 * 100005];
int lazy[4 * 100005] = {0};
void build(int ind, int low, int high, vector<int> &arr)
{
    if (low == high)
    {
        seg[ind] = arr[low];
        return;
    }

    int mid = (low + high) >> 1;
    build(2 * ind + 1, low, mid, arr);
    build(2 * ind + 2, mid + 1, high, arr);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}
void rangeupdate(int ind, int val, int low, int high, int l, int r, vector<int> &arr)
{

    if (low >= l && r <= high)
    {
        seg[ind] += (high - low + 1) * val;
        if (low != high)
        {
            lazy[2 * ind + 1] = val;
            lazy[2 * ind + 2] = val;
        }
    }
    else if (high < l || low > r || low > high)
    {
        return;
    }
    else
    {
        if (low != high)
        {
            int mid = (low + high) >> 1;
            rangeupdate(2 * ind + 1, val, low, mid, l, r, arr);
            rangeupdate(2 * ind + 2, val, mid + 1, high, l, r, arr);
            seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
        }
    }
}
int querySumLazy(int ind, int low, int high, int l, int r, vector<int> &arr)
{

    if (lazy[ind] != 0)
    {
        seg[ind] += (high - low + 1) * lazy[ind];
        lazy[2 * ind + 1] += lazy[ind];
        lazy[2 * ind + 2] += lazy[ind];
        lazy[ind] = 0;
    }
    if (low >= l && high <= r)
    {
        return seg[ind];
    }
    else if (low > r || high < l)
    {
        return 0;
    }
    else
    {
        int mid = (low + high) / 2;
        int l_sum = querySumLazy(2 * ind + 1, low, mid, l, r, arr);
        int r_sum = querySumLazy(2 * ind + 2, mid + 1, high, l, r, arr);
        return l_sum + r_sum;
    }
}
// int query(int ind,int low,int high,int l,int r,vector<int>&arr){

// if(l>high  || r<low){
//     return 0;
// }else if(l<=low && high<=r){
//     return seg[ind];
// }else{
//     int mid=(low+high)>>1;
//     int l_max=query(2*ind+1,low,mid,l,r,arr);
//     int r_max=query(2*ind+2,mid+1,high,l,r,arr);
//     return l_max+r_max;
// }
// }
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
    int x;
    cin >> x;
    int l = 0, r = 1;
    int cal = arr[0];
    int res = abs(x - arr[0]);
    while (l < n && r < n)
    {
        if (abs((cal & arr[r]) - x) > abs(cal - x))
        {
            l = r;
            cal = arr[r];
        }
        else
        {
            cal = cal & arr[r];
            res = min(res, abs(cal - x));
        }
        res = min(res, abs(cal - x));
        r++;
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