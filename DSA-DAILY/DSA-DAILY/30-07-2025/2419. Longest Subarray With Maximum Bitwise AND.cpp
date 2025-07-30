#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0,maxs=0,s=0;
        for(int num:nums){
            if(num>maxs){
                maxs=num;
                ans=s=0;
            }
            if(maxs==num){
                s++;
            }
            else{
                s=0;
            }
            ans=max(ans,s);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter Array: ";
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int result = sol.longestSubarray(a);
    cout << "Length of longest subarray with maximum bitwise AND: " << result << endl;
    return 0;
}