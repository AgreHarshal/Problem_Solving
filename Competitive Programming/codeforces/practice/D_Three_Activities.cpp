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
  if(a.first!=b.first){
    return a.first>b.first;
  }else{
    return b.second<b.second;
  }
}
void solve()
{
  int n;
  cin>>n;
  vector<pair<int,int>>a;
  vector<pair<int,int>>b;
  vector<pair<int,int>>c;
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x;
    a.push_back({x,i});
  }
  for(int i=0;i<n;i++){
   int x,y;
    cin>>x;
    b.push_back({x,i});
  }
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x;
    c.push_back({x,i});
  }
sort(a.begin(),a.end(),comp);
sort(b.begin(),b.end(),comp);
sort(c.begin(),c.end(),comp);
int res=0;
for(int i=0;i<3;i++){
  for(int j=0;j<3;j++){
    for(int k=0;k<3;k++){
      if(a[i].second!=b[j].second && a[i].second!=c[k].second && b[j].second!=c[k].second){
        res=max(res,a[i].first+b[j].first+c[k].first);
      }
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