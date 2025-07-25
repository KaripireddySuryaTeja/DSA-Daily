import java.util.*;

class Solution {
    // Returns the maximum sum of a subarray with all unique elements
    public int maximumUniqueSubarray(int[] nums) {
        int currs = 0, s = 0, res = 0;
        Set<Integer> seen = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            while (seen.contains(nums[i])) {
                seen.remove(nums[s]);
                currs -= nums[s];
                s++;
            }
            currs += nums[i];
            seen.add(nums[i]);
            res = Math.max(res, currs);
        }
        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        // Example input
        int[] nums = {4, 2, 4, 5, 6};
        int result = sol.maximumUniqueSubarray(nums);
        System.out.print("Input array: ");
        for (int n : nums) System.out.print(n + " ");
        System.out.println();
        System.out.println("Maximum Erasure Value: " + result);

        // Sample Output:
        // Input array: 4 2 4 5 6 
        // Maximum Erasure Value: 17
    }
}