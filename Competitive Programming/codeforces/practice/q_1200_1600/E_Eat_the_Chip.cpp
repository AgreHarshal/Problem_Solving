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
  int h,w,xa,ya,xb,yb;
  cin>>h>>w>>xa>>ya>>xb>>yb;
  
  if(h==1 || xa>xb){
    cout<<"Draw"<<endl;
    return;
  }
  if(w==1){
    if(abs(xa-xb)%2){
        cout<<"Alice"<<endl;
    }else{
        cout<<"Bob"<<endl;
    }
    return ;
  }
  if(ya==yb){
     if(abs(xa-xb)%2){
        cout<<"Alice"<<endl;
    }else{
        cout<<"Bob"<<endl;
    }
  }else{

  
    int s=(abs(xa-xb)+1)/2;
    if(abs(xa-xb)%2){
        //alice or draw
        if(min(yb+s-1,w)>min(ya+s,w)){
            cout<<"Draw"<<endl;
        }else if(max(1ll,yb-s+1)<max(1ll,ya-s)){
            cout<<"Draw"<<endl;
        }else{
            cout<<"Alice"<<endl;
        }
    }else{
        //bob or draw
         
       if(min(yb+s,w)<min(ya+s,w)){
            cout<<"Draw"<<endl;
        }else if(max(1ll,yb-s)>max(1ll,ya-s)){
cout<<"Draw"<<endl;
        }else{
            cout<<"Bob"<<endl;
        }

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