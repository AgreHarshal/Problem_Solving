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
  int n,m,k;
  cin>>n>>m>>k;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<int>b(m);
  for(int i=0;i<m;i++){
    cin>>b[i];
  }
  int t_a=0;
  int t_b=0;
//   sort(a.begin(),a.end());
//   sort(b.begin(),b.end());
  vector<int>freq1(k+1,0);
  vector<int>freq2(k+1,0);
  for(int i=0;i<n;i++){
    if(a[i]<=k){
        freq1[a[i]]++;
    }
  }
  for(int i=0;i<m;i++){
    if(b[i]<=k){
        freq2[b[i]]++;
    }
  }
  for(int i=1;i<=k;i++){
    if(freq1[i]==0 && freq2[i]>=1){
        t_b++;
    }else if(freq1[i]>=1 && freq2[i]==0){
        t_a++;
    }else if(freq1[i]==0 && freq2[i]==0){
        cout<<"NO"<<endl;
        return;
    }
  }
  if(t_a>k/2 || t_b>k/2 ){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
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