#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0&&freq[nums[i]]<1){
                freq[nums[i]]++;
                sum+=nums[i];
            }
        }
        if(sum==0){
            sum=INT_MIN;
            for(int i=0;i<nums.size();i++){
                sum=max(nums[i],sum);
            }
        }
        return sum;
    }
};

int main() {
    vector<int> nums = {4, 2, 4, 5, 6}; // Example input
    Solution sol;
    int result = sol.maxSum(nums);
    cout << "Maximum Unique Subarray Sum After Deletion: " << result << endl;
}