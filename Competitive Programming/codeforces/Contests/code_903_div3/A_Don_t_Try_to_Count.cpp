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
  int n,m;
  cin>>n>>m;
  string x,s;
cin>>x>>s;
if(x.find(s)!=x.end()){
    cout<<"0"<<endl;
    return ;
}
int len=n;
int cnt=1;
while(len<=m*n){
    x+=x;
    if(x.find(s)!=x.end()){
cout<<cnt<<endl;
return ;
    }
    len+=len;
    cnt++;
}
cout<<"-1"<<endl;

}
int32_t main(){

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