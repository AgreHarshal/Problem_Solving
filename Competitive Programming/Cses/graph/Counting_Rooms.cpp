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
// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
void dfs(int v_x, int v_y, int p_x, int p_y, vector<vector<char>> &arr, int m, int n, vector<vector<bool>> &vis)
{
    vis[v_x][v_y] = true;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++)
    {
        int new_x = v_x + dx[i];
        int new_y = v_y + dy[i];

        if (new_x < n && new_x >= 0 && new_y < m && new_y >= 0 && arr[new_x][new_y] == '.' && vis[new_x][new_y] == false)
        {

            dfs(new_x, new_y, v_x, v_y, arr, m, n, vis);
        }
    }
}
void solve()
{
  
  int n,k;
  cin>>n>>k;
  vector<int>rates(n);
  vector<int>strategy(n);

for(int i=0;i<n;i++){
    cin>>rates[i];
}
for(int i=0;i<n;i++){
    cin>>strategy[i];
}
int max_res=INT_MIN;;
int res=0;
for(int i=0;i<n;i++){
if(strategy[i]==-1){
    res-=rates[i];
}else if(strategy[i]==1){
    res+=rates[i];
}
}
int tmp=0;
max_res=max(max_res,res);
int l=k/2;
int r=k/2;
while(r<k){
    tmp+=(rates[r]);
    r++;
}
int lll=0;
cout<<tmp<<endl;
for(int i=k;i<n;i++){
if(strategy[i]==-1){
    tmp-=rates[i];
}else if(strategy[i]==1){
    tmp+=rates[i];
}
cout<<tmp<<endl;
max_res=max(tmp,res);
cout<<max_res<<endl;
}
r++;
while(r<n){
tmp+=(rates[r]);
tmp-=rates[l];
if(strategy[lll]==-1){
    tmp-=rates[lll];
}else if(strategy[lll]==1){
    tmp+=rates[lll];
}
lll++;
r++;
l++;
cout<<tmp<<" "<<max_res<<endl;
max_res=max(max_res,tmp);
}
cout<<max_res<<endl;

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
    // int tc;
    // cin >> tc;
    // for (int t = 1; t <= tc; t++)
    // {
    //     // cout << 'CASE' << t << ':' ;
    //     solve();
    // }
    return 0;
}