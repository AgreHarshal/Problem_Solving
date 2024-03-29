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
string s;
cin>>s;
int n=s.size();
int zero=0,one=0;
for(int i=0;i<n;i++){
    if(s[i]=='0'){
        zero++;
    }else{
        one++;
    }
}
if(zero==one){
    cout<<"0"<<endl;
    return ;
}
for(int i=0;i<n;i++){
    if(s[i]=='0' && one>0){
        one--;
    }else if(s[i]=='0'){
        cout<<n-i<<endl;
        return ;
    }else if(s[i]=='1' && zero>0){
zero--;
    }else{
        cout<<n-i<<endl;
        return ;
    }
    
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