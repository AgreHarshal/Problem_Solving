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
bool comp(pair<int,int>&a,pair<int,int>&b){
 return (a.first+a.second)>(b.first+b.second);
}
void solve()
{
  int n;
  cin>>n;
  vector<pair<int,int>>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i].first;
  }
  for(int i=0;i<n;i++){
    cin>>arr[i].second;
  }
  sort(arr.begin(),arr.end(),comp);
int res=0;
for(int i=0;i<n;i++){
    if(i%2==0){
          res+=((arr[i].first)-1);
    }else{
        res-=(arr[i].second-1);
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