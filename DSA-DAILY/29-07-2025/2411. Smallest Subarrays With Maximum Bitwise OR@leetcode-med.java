class Solution {
    public int[] smallestSubarrays(int[] nums) {
        int n=nums.length;
        int[] ans=new int[n];
        for(int i=0;i<n;i++){
            int x=nums[i];
            ans[i]=1;
            for(int j=i-1;j>=0&&(nums[j]|x)!=nums[j];--j){
                nums[j]|=x;
                ans[j]=i-j+1;
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {1, 2, 3, 4};
        int[] result = solution.smallestSubarrays(nums);
        for (int res : result) {
            System.out.print(res + " ");
        }
        // Output: [4, 3, 2, 1]
    }
}