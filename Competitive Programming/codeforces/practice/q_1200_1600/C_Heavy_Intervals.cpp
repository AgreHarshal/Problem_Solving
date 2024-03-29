//instead of making intervals equal if we assign larger weight to smaller imnterval 
// it will result in minimizing the result so just sorting and taking difference wont work 
// ex L:1 2 R:3 4 W:1 2
// will use stack like data structure to find the closest interval so that intervals will be smallest 
// to largets 
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
  vector<pair<int,char>>a;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a.push_back({x,'l'});
  }

 for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a.push_back({x,'r'});
  }
  sort(a.begin(),a.end());
  vector<int>c(n);

  for(int i=0;i<n;i++){
    cin>>c[i];
  }
  stack<pair<int,char>>s;
  vector<int>diff;
for(int i=0;i<2*n;i++){
    if(a[i].second=='l'){
s.push(a[i]);
    }else{
        auto tp=s.top();
        s.pop();
        diff.push_back(a[i].first-tp.first);
    }
}

  sort(c.begin(),c.end());
  sort(diff.begin(),diff.end(),greater<int>());
  int res=0;
  for(int i=0;i<n;i++){
    res+=(c[i]*diff[i]);
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