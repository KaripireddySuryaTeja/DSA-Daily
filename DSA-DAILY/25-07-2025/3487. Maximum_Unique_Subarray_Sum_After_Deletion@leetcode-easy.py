from typing import List

class Solution:
    def maxSum(self, nums: List[int]) -> int:
        sum=0
        freq={}
        for num in nums:
            if num>0 and freq.get(num,0)<1:
                sum+=num
                freq[num]=1
        
        if(sum==0):
            sum=max(nums)
        return sum

if __name__ == "__main__":
    nums = [4, 2, 4, 5, 6]  # Example input
    sol = Solution()
    result = sol.maxSum(nums)
    print("Maximum Unique Subarray Sum:", result)