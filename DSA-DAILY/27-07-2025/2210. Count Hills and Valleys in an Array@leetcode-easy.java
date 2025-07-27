import java.util.*;
class Solution {
    public int countHillValley(int[] nums) {
        int res=0,j=0,n=nums.length;
        for(int i=1;i<n-1;i++){
            if((nums[j]<nums[i]&&nums[i]>nums[i+1])||(nums[j]>nums[i]&&nums[i]<nums[i+1])){
                res++;
                j=i;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Solution solution=new Solution();
       // int[] nums = {2, 4, 1, 1, 6, 5}; output: 3
       int n;
       Scanner scanner = new Scanner(System.in);
       System.out.print("Enter the number of elements in the array: ");
       n = scanner.nextInt();
       int[] nums = new int[n];
       System.out.println("Enter the elements of the array:");
       for (int i = 0; i < n; i++) {
           nums[i] = scanner.nextInt();
       }
        int result = solution.countHillValley(nums);
        System.out.println("Number of hills and valleys: " + result); 
    }
}
