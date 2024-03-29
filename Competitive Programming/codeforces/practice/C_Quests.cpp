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
  int n,k;
  cin>>n>>k;
  vector<int>a(n);
vector<int>b(n);

  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  
  for(int i=0;i<n;i++){
    cin>>b[i];
  }

  int ans=0;
  int res=0;
  n=min(n,k);
  for(int i=0;i<n;i++){
    ans+=a[i];
    if(i!=0){
      b[i]=max(b[i],b[i-1]);
    }
    if(i<k){
        res=max(res,ans+b[i]*(k-i-1));
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