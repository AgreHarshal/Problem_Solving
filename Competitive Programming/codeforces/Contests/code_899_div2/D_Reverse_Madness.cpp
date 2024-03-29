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
// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
string reverseS(string &s,
                int l, int h)
{
    int n = h - l;
    string str = s;
    // Swap character starting
    // from two corners
    for (int i = 0; i < n / 2; i++)
    {
        char temp = str[i + 1];

        str[i + 1] = str[n - i - 1 + l];
        str[n - i - 1 + l] = temp;
    }
    return str;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(k);
    vector<int> b(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
    }
    vector<int> mark(n + 1, 0);
    int q;
    cin >> q;
    for (int z = 0; z < q; z++)
    {
        int x;
        cin >> x;
        int ri = lower_bound(b.begin(), b.end(), x) - b.begin();
        int l_temp = a[ri];
        int r_temp = b[ri];
        int l = min(x, r_temp + l_temp - x);
        int r = max(x, r_temp + l_temp - x);
        cout << "l-" << l << " r-" << r << endl;
        mark[l] = mark[l] ^ 1;
        mark[r] = mark[r] ^ 1;
    }
    cout << s << endl;
    vector<pair<int, int>> res;
    int cnt = 0;
    int ai, bi;
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] == 1 && cnt == 0)
        {
            ai = i;
            cnt++;
        }
        else if (mark[i] == 1 && cnt == 1)
        {
            bi = i;
            cnt = 0;
            res.push_back({ai, bi});
            cout << ai << " " << bi << endl;
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        ai = res[i].first - 1;
        bi = res[i].second - 1;
        string new1 = "";
        cout << ai << " " << bi << endl;
        for (int j = ai; j <= bi; j++)
        {
            new1 += s[j];
        }

        reverse(new1.begin(), new1.end());

        for (int j = ai; j <= bi; j++)
        {
            s[j] = new1[j - ai];
        }
        cout << s << endl;
    }
    cout << s << endl;
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