import java.util.*;

class Solution {
    public int maxSum(int[] nums) {
        Map<Integer,Integer> seen=new HashMap<>();
        int sum=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>0 && seen.getOrDefault(nums[i],0)<1){
                sum+=nums[i];
                seen.put(nums[i],1);
            }   
        } 
        if(sum==0){
            sum=Integer.MIN_VALUE;
            for(int i=0;i<nums.length;i++){
                sum=Math.max(sum,nums[i]);
            }
        }
        return sum;
    }
}

class  Main {
    public static void main(String[] args) {
        int[] nums = {4, 2, 4, 5, 6}; // Example input
        Solution sol = new Solution();
        int result = sol.maxSum(nums);
        System.out.println("Maximum Unique Subarray Sum After Deletion: " + result);
    }
}