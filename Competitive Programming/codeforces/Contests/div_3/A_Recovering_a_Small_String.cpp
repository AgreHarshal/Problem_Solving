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
  cin>>n;
if(n<=28){
    int temp=n-3;
    cout<<"aa"<<char('a'+temp)<<endl;
}else if(n<=53){
    n-=26;
    int temp=n-1;
    temp--;
    cout<<"a"<<char('a'+temp)<<"z"<<endl;
}else{
    n-=26;
    n-=26;
    n-=1;
    cout<<char('a'+n)<<"zz"<<endl;
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