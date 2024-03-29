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
    cin >> n;
    string s;
    cin >> s;
    if (is_sorted(s.begin(), s.end()))
    {
        cout << "0" << endl;
        return;
    }
    vector<int>lex_idx;
    lex_idx.push_back(0);
    for(int i=1;i<n;i++){
        while(!lex_idx.empty() && s[lex_idx.back()]<s[i]){
            lex_idx.pop_back();
        }
        lex_idx.push_back(i);
    }
    int first=lex_idx[0];
    int dup=0;

    for(int i=0;i<lex_idx.size();i++){
        if(s[lex_idx[i]]==s[first]){
            dup++;
        }
    }

    for(int i=0;i<lex_idx.size()/2;i++){
        swap(s[lex_idx[i]],s[lex_idx[lex_idx.size()-i-1]]);
    }
    if(is_sorted(s.begin(),s.end())){
        cout<<lex_idx.size()-dup<<endl;
    }else{
        cout<<"-1"<<endl;
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