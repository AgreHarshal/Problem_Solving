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
 
    int cost = 0;
    int a = n + 1, b = n + 1; // a >= b
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
 
        if (x <= b) {
            b = x;
        } else if (x <= a) {
            a = x;
        } else {
            b = x;
            ++cost;
        }
 
        if (a < b) {
            swap(a, b);
        }
    }
 
    cout << cost << "\n";
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