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
bool f(vector<int>&arr,int mid){
    int sum1=0;
    int sum2=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(sum1+arr[i]<=mid){
            sum1+=arr[i];
        }else{
            sum2+=arr[i];
            sum1=0;
        }
    }
   
    if(sum2<=mid){
        return true;
    }else{
        return false;
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
  int low=1;
  int high=1e15;
int res=high;
  while(low<=high){
    int mid=low+(high-low)/2;
 if(f(arr,mid)){
    res=mid;
    high=mid-1;
 }else{
    low=mid+1;
 }
  }
  cout<<high+1<<endl;
  
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