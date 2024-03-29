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
  int a,b,x;
  cin>>a>>b>>x;
int r=0;
if(a<b){
    int temp=b;
    b=a;
    a=temp;
}
int res=a-b;
for(int i=60;i>=0;i--){
    if(((1ll<<i)&a) && (((1ll<<i)&b)==0)){
        if((r|(1ll<<i))<=x){
           r= r | (1ll<<i);
        }
       res=min(abs((a^r) - (b^r)),res);
    }
}
r=0;
for(int i=0;i<=60;i++){
    if(((1ll<<i)&a) && (((1ll<<i)&b)==0)){
        if((r|(1ll<<i))<=x){
           r= r | (1ll<<i);
        }
       res=min(abs((a^r) - (b^r)),res);
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