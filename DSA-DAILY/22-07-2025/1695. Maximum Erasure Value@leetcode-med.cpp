#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Returns the maximum sum of a subarray with all unique elements
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int res = 0, currs = 0, s = 0;
        for (int i = 0; i < nums.size(); i++) {
            // If nums[i] is already in the set, remove elements from the start until it's unique
            while (seen.find(nums[i]) != seen.end()) {
                seen.erase(nums[s]);
                currs -= nums[s];
                s++;
            }
            currs += nums[i];
            seen.insert(nums[i]);
            res = max(res, currs);
        }
        return res;
    }
};

int main() {
    Solution sol;
    // Example input
    vector<int> nums = {4, 2, 4, 5, 6};
    int result = sol.maximumUniqueSubarray(nums);
    cout << "Input array: ";
    for (int n : nums) cout << n << " ";
    cout << endl;
    cout << "Maximum Erasure Value: " << result << endl;

    // Sample Output:
    // Input array: 4 2 4 5 6 
    // Maximum Erasure Value: 17

    return 0;
}