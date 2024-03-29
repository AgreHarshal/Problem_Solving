#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

void precal() {}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void solve() {
    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;

    vector<int> a(n);
    map<int, map<int, int>> mp1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int key = a[i] % x;
        int value = a[i] % y;
        if (mp1.find(key) == mp1.end()) {
            mp1[key] = map<int, int>();
        }
        map<int, int>& mp = mp1[key];
        mp[value] = mp[value] + 1;
    }

    int res = 0;
    for (int i : a) {
        int complement = (x - (i % x)) % x;
        if (i % x == complement) {
            res += mp1[complement][i % y] - 1;
        } else {
            res += mp1[complement][i % y];
        }
    }

    cout << res / 2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(10);
    precal();
    // solve();
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << 'CASE' << t << ':' ;
        solve();
    }
    return 0;
}
