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
   int pos=0,neg=0,zero=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    if(arr[i]>0){
        pos++;
    }else if(arr[i]==0){
        zero++;
    }else{
        neg++;
    }
  }
  if(zero){
    cout<<"0"<<endl;
    return ;
  }
  if(neg%2){
    cout<<"0"<<endl;
  }else{
    cout<<"1"<<endl;
    cout<<"1 0"<<endl;
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