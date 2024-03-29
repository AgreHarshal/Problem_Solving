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
vector<int>dp(n,0);
map<int,int>mp;
mp[0]=1;
for(int i=1;i<n;i++){
 if(arr[i]==arr[i-1]){
    dp[i]=dp[i-1];
 }else{

    dp[i]=dp[i-1]+1;
    mp[dp[i]]=i+1;
 }
}
 int q;
 cin>>q;
 for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
if(dp[l-1]==dp[r-1]){
    cout<<"-1 -1"<<endl;
}else{
    int x=l;
    int y=mp[dp[l-1]+1];
    cout<<x<<" "<<y<<endl;
}
 } 
  cout<<endl;
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