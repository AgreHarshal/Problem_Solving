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
    if(a.first==b.first){
return a.second<b.second;

    }else{
        return a.first<b.first;
    }
}
void solve()
{
  int n,k;
  cin>>n>>k;
  vector<pair<int,int>>arr;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr.push_back({x,i});
  }
sort(arr.begin(),arr.end(),comp);
int maxi=INT_MAX;
int maxi_2=0;
int curr_max=0;
int curr_max2=0;
for(int i=1;i<=n;i++){
    if(i==n ||  arr[i].first!=arr[i-1].first){
        if(i<n && arr[i].second>curr_max){
            curr_max=arr[i].second;
        }
        if(n-1-arr[i-1].second>=curr_max){
            curr_max2=curr_max;
            curr_max=n-1-arr[i-1].second;
        }
        if(curr_max<maxi){
            maxi=curr_max;
            maxi_2=curr_max2;
         }else if(curr_max==maxi){
            maxi_2=min(curr_max2,maxi_2);
         }
         curr_max=0;
         curr_max2=0;
    }else{
if(arr[i].second-arr[i-1].second-1>=curr_max){
            curr_max2=curr_max;
            curr_max=arr[i].second-arr[i-1].second-1;
        }
    }
}
cout<<min((maxi+1)/2,maxi_2)<<endl;
  
  
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