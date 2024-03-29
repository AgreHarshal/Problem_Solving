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
  int x,n;
  cin>>x>>n;
  int res=1;
  for(int i=1;i*i<=x;i++){
         if(x%i==0){
            int cnt1=x/i;
            int cnt2=x/(x/i);
            if(cnt1>=n){
                res=max(res,i);
            }
            if(cnt2>=n){
                res=max(res,x/i);
            }
         }
  }
  cout<<res<<endl;
  
  
  
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