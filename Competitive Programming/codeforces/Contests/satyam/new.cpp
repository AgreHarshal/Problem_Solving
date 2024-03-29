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
int help(int i,unordered_map<int,int>mp,vector<int>&arr){
if(i==arr.size()){
    return 0;
}
if(mp.find(arr[i])!=mp.end()){
    int maxi=0;
    maxi=max(maxi,help(i+1,mp,arr));
    int add=i-mp[arr[i]];
    cout<<add<<endl;
    mp.erase(mp[arr[i]]);
    maxi=max(maxi,add+help(i+1,mp,arr));
    return maxi;
}else{
    mp[arr[i]]=i;
    return help(i+1,mp,arr);
}

}
void solve()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  unordered_map<int,int>mp;
  int res=n-help(0,mp,arr);
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