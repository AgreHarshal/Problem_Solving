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
  int n,k;
  cin>>n>>k;
  vector<int>arr(n+1,0);

int diff=n/k;
int add=1;
for(int i=1;i<=k;i+=2){
    arr[i]=add;
    add=add+diff;
}
int res=n;
for(int i=2;i<=k;i+=2){
    arr[i]=res;
    res-=diff;
}
add=0;
for(int i=1;i<=k%n;i+=2){
    arr[i]+=add;
    add++;
}
add=0;
for(int i=2;i<=k%n;i+=2){
    arr[i]-=add;
    add++;
}

for(int i=k+1;i<=n;i++){
   if(i%2){
    arr[i]=arr[i-k]+1;
   }else{
    arr[i]=arr[i-k]-1;
   }
}
for(int i=1;i<=n;i++){
    cout<<arr[i]<<" ";
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