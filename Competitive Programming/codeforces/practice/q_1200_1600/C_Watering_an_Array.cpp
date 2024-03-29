#include <bits/stdc++.h>
using namespace std;
#define int long long
//#define endl "/"
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
  int n,k,d;
  cin>>n>>k>>d;
  vector<int>arr(n);
  int same_cnt=0;

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int>b(k);
  for(int i=0;i<k;i++){
    cin>>b[i];
  }

int j=0;
int res=0;
while(j<min(d,2*n)){//2*n as by this point weve already gained n points so need to further check
    int same=0;
    for(int i=0;i<n;i++){
        if(arr[i]==i+1){
            same++;
        }
    }
     res=max(res,(d-j-1)/2+same);
     for(int i=0;i<b[j%k];i++){
        arr[i]++;
     }
     j++;
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