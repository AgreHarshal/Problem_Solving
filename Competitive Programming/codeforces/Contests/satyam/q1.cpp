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

int help(vector<int>arr,int i,int j,int sum){
    if(j-i<=0){
        return 0;
    }
    int maxi=0;
if(arr[i]+arr[j]==sum){
    maxi=max(maxi,1+help(arr,i+1,j-1,sum));
}
if(arr[i]+arr[i+1]==sum){
    maxi=max(maxi,1+help(arr,i+2,j,sum)); 
}
if(arr[j-1]+arr[j]==sum){
    maxi=max(maxi,1+help(arr,i,j-2,sum));
}
return maxi;

}

void solve()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
int res=0;
res=max(res,help(arr,1,n-2,arr[0]+arr[n-1]));
res=max(res,help(arr,2,n-1,arr[0]+arr[1]));
res=max(res,help(arr,0,n-3,arr[n-2]+arr[n-1]));
  cout<<res+1<<endl;
  
}
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  precal();
  solve();
//   int tc;
//   cin >> tc;
//   for (int t = 1; t <= tc; t++)
//   {
//       // cout << 'CASE' << t << ':' ;
//       solve();
//   }
  return 0;
}