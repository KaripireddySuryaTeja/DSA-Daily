#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //this is a dynamic programming solution
    //we use a dp array where dp[i] represents the number of subsets that can achieve 
    int countMaxOrSubsets(vector<int>& nums) {
        int max=0;
        vector<int>dp(1<<17,0);
        dp[0]=1;
        for(int num:nums){
            for(int i=max;i>=0;i--){
                dp[i | num]+=dp[i];
            }
            max |=num;
        }
        return dp[max];
    }
};
//another approach is to use backtracking which i will implemented in other language
int main(){
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << sol.countMaxOrSubsets(nums) << endl;
    return 0;
}