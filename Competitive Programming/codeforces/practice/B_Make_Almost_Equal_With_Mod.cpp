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
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  bool  o=false;
  bool e=false;
  int res=2;
  while(1){
 
 for(auto i:arr){
  if(i%2){
    o=true;
  }else{
    e=true;
  }
 }
 if(o && e){
  cout<<res<<endl;
  break;
 }else{
  for(int i=0;i<n;i++){
    arr[i]/=2;
  }
  o=false;
  e=false;
  res*=2;
 }
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