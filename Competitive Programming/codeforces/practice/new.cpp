#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countSubarraysWithDuplicatePairs(std::vector<int> &numbers, int k) {
    int ans = 0;
int n=numbers.size();
   unordered_map<int,int>mp;
   int i=0,j=0;
   int freq=0;
   while(j<n && i<n){
         mp[numbers[j]]++;
         if(mp[numbers[j]]%2==0){
             freq++;
         }

         if(freq>=k){
            ans++;
            ans+=(n-j);
            mp[numbers[i]]--;
            if(mp[numbers[i]]<=1 ){
                 freq--;
            }
            if(freq>=k){
                ans++;
            }
            i++;
         }
         j++;
   }
   return ans;

}

int main() {
    std::vector<int> numbers = {2, 2, 2, 2, 2, 2};
    int k = 3;

    int result = countSubarraysWithDuplicatePairs(numbers, k);
    std::cout << result << std::endl;

    return 0;
}
