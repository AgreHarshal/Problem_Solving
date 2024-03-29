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
  int i=1;
  dp[0]=0;
  dp[1]=1;
  while(i<n-1){
    int left=arr[i]-arr[i-1];
    int right=arr[i+1]-arr[i];
    if(left>right){
        dp[i+1]=dp[i]+1;
    }else{
        dp[i+1]=dp[i]+abs(arr[i+1]-arr[i]);
    }
    i++;
  }
  vector<int>dpr(n,0);
  dpr[n-1]=0;
  dpr[n-2]=1;
  
  i=n-2;
  while(i>0){
   int l=arr[i]-arr[i-1];
   int r=arr[i+1]-arr[i];
   if(l<r){
    dpr[i-1]=dpr[i]+1;
   }else{
    dpr[i-1]=dpr[i]+abs(arr[i]-arr[i-1]);
   }
   i--;
  }
  int m;
  cin>>m;
  while(m--){
    int c1,c2;
    cin>>c1>>c2;
    if(c1<c2){
        cout<<abs(dp[c2-1]-dp[c1-1])<<endl;
    }else{
        cout<<abs(dpr[c1-1]-dpr[c2-1])<<endl;
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