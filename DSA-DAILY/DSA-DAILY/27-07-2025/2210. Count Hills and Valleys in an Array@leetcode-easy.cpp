#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res=0,j=0;
        for(int i=1;i<nums.size()-1;i++){
            if((nums[i]>nums[j]&&nums[i]>nums[i+1])||(nums[i]<nums[j]&&nums[i]<nums[i+1])){
                res++;
                j=i;
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2, 4, 1, 1, 6, 5};
    int result = sol.countHillValley(nums);
    cout << "Number of hills and valleys: " << result << endl; // Output: 3
    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(1)