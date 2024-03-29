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
 int i=0,j=s.size()-1;
 int cnt_s=0;
 int cnt_p=0;
 int cnt_h=0;
 int cnt_d=0;
 
 unordered_map<char,int>mp2;
 for(int k=i+1;k<=j;k++){
    mp2[k]++;
    if(s[k]=='H' && s[k-1]!='H'){
        cnt_h++;
    }else if(s[k]=='P' && s[k-1]!='P'){
        cnt_p++;
    }else if(s[k]=='D' && s[k-1]!='D'){
        cnt_d++;
    }else if(s[k]=='S' && s[k-1]!='S'){
        cnt_s++;
    }
 }
 mp2[s[0]]++;
 int max_diff=mp2.size();
 int res=0;
 int diff=0;
 unordered_map<char,int>mp;
 while(i<j && diff<max_diff-1){
    if(mp.count(s[i]==0)){
        mp[s[i]]++;
        diff++;
        if(s[i]=='H'){
        res+=(cnt_h-1);
    }else if(s[i]=='P'){
        res+=(cnt_p-1);
    }else if(s[i]=='D'){
        res+=(cnt_d-1);
    }else{
        res+=(cnt_s-1);
    }
    }else{
        i++;

    }
    if(diff==max_diff-1){
        break;
    }
    if(mp.count(s[j]==0)){
        mp[s[j]]++;
        diff++;
         if(s[j]=='H'){
        res+=(cnt_h-1);
    }else if(s[j]=='P'){
        res+=(cnt_p-1);
    }else if(s[j]=='D'){
        res+=(cnt_d-1);
    }else{
        res+=(cnt_s-1);
    }
    }else{
        j--;
    }
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
 solve();
//  int tc;
//  cin >> tc;
//  for (int t = 1; t <= tc; t++)
//  {
//      // cout << 'CASE' << t << ':' ;
//     solve();
//   }
  return 0;
}