class Solution {
    public int longestSubarray(int[] nums) {
        int ans=0,s=0,maxs=0;
        for(int num:nums){
            if(num>maxs){
                maxs=num;
                s=ans=0;
            }
            if(maxs==num){
                s++;
            }else{
                s=0;
            }
            if(ans<s)ans=s;
        }   
        return ans;
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {1, 2, 3, 4, 3, 2, 1};
        int result = solution.longestSubarray(nums);
        System.out.println(result); // Output: 4
    }
}
