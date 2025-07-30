from typing import List
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        maxs=ans=s=0
        for num in nums:
            if num > maxs:
                ans=s=0
                maxs=num
            if num == maxs:
                s+=1
            else:
                s=0
            ans=max(ans,s)
        return ans
    
if __name__ == "__main__":
    sol = Solution()
    nums = [1, 2, 4, 4, 4, 2, 1]
    print(sol.longestSubarray(nums))
