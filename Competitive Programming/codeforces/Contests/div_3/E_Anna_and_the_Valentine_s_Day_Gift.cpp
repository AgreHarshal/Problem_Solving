#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
void precal()
{
}
int c(int num){
    int res = 0;
    while (num % 10 == 0) {
        res++;
        num /= 10;
    }
    return res;
}
int cntall(int num){
    int res = 0;
    while (num >0) {
        res++;
        num /= 10;
    }
    return res;
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
        int n, m;
        cin>> n>> m;
        vector<int> arr(n);
        vector<int> cnt(n);
        int ans=0;
        for(int i=0; i< n; i++){
            cin>> arr[i];
            int num=arr[i];
            int res = 0;
           while (num % 10 == 0) {
        res++;
        num /= 10;
    }
    cnt[i]=res;
    num=arr[i];
     res = 0;
    while (num >0) {
        res++;
        num /= 10;
    }
    ans+=res;
        }

        sort(cnt.begin(), cnt.end(), greater<int>());
        for(int i=0; i< n; i++){
            if(i%2==0){
                ans-= cnt[i];
            }
        }
        if(ans> m){
            cout<< "Sasha"<<endl;
        }
        else{
            cout<< "Anna"<<endl;
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