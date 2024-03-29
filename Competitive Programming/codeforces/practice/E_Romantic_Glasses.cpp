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
  int my_sum=0;
  int love_sum=0;
  map<int,int>mp;
  mp[0]++;
  for(int i=0;i<n;i++){
    if(i%2==0){
        my_sum+=arr[i];
        
        if(mp.find(my_sum-love_sum)!=mp.end()){
            cout<<"YES"<<endl;
        return ;
        }
        mp[my_sum-love_sum]++;
    }else{
        love_sum+=arr[i];
        if(mp.find(my_sum-love_sum)!=mp.end()){
            cout<<"YES"<<endl;
        return ;
        }
         mp[my_sum-love_sum]++;
    }
  }
  cout<<"NO"<<endl;
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