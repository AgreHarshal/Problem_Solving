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
        cin>> n;
        vector<int> arr(n);
        for(int i=0; i< n; i++){
            cin>> arr[i];
        }
        int a = arr[0];
        int b = arr[n-1];
        int left_ind=0, right_ind=n-1;
         for(right_ind=n-1; right_ind>=0; right_ind--){
            if(arr[right_ind]!= b){
                break;
            }
        }
        for(left_ind=0; left_ind< n; left_ind++){
            if(arr[left_ind]!= a){
                break;
            }
        }
       
        if(a== b){
            if(left_ind== n){
                cout<< 0<<endl;
            }
            else{
                cout<< right_ind-left_ind+1<<endl;
            }
        }
        else{
            int x = n-left_ind;
            int y = right_ind+1;
            cout<< min(x, y)<<endl;
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