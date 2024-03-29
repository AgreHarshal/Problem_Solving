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
  int odd=0,even=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
    int odd_sum=0;
  int even_sum=0;
  if(arr[0]%2){
    odd++;
    odd_sum+=arr[0];
  }else{
    even_sum+=arr[0];
  }
  
cout<<arr[0]<<" ";
  for(int i=1;i<n;i++){
    if(arr[i]%2){
        odd++;
        odd_sum+=arr[i];
    }else{
        even++;
        even_sum+=arr[i];
    }
    int cnt=odd/3;
    if(odd%3==1){
        cout<<odd_sum+even_sum-cnt-1<<" ";
    }else{
        cout<<odd_sum+even_sum-cnt<<" ";
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