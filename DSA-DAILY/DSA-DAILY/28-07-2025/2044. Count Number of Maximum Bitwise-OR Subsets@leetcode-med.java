import java.util.*;
class Solution {
    public int countMaxOrSubsets(int[] nums) {
        int maxi=0;
        for(int n:nums){
            maxi|=n;
        }
        return backtrack(nums,maxi,0,0);
    }

    private int backtrack(int[] nums,int maxi,int ind,int curr){
        if(ind==nums.length){
           return (curr==maxi)?1:0;
        } 
        int consider=backtrack(nums,maxi,ind+1,curr|nums[ind]);
        int notconsider=backtrack(nums,maxi,ind+1,curr);
        return consider+notconsider;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Enter the number of elements in the array:");
            int n= scanner.nextInt();
            int[] nums = new int[n];
            System.out.println("Enter the elements of the array:");
            for(int i=0;i<n;i++){   
                nums[i] = scanner.nextInt();
            }
            int result = sol.countMaxOrSubsets(nums);
            System.out.println(result);
        }catch (Exception e) {
            System.out.println("An error occurred: " + e.getMessage());
        }
    }
}