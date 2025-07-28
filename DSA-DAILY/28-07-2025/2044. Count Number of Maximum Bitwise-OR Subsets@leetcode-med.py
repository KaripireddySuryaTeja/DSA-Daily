import random
from typing import List
class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        maxi=0
        for i in nums:
            maxi |=i
        return self.backtrack(nums,maxi,0,0)
    
    def backtrack(self,nums:List[int],maxi:int,ind:int,curr:int):
        if ind == len(nums):
            return 1 if curr == maxi else 0 
               
               
        if curr is maxi:
            return 1<<(len(nums)-ind)
        consider=self.backtrack(nums,maxi,ind+1,curr|nums[ind])
        notconsider=self.backtrack(nums,maxi,ind+1,curr)
        return consider+notconsider 
    
if __name__== "__main__":
    sol=Solution()
    nums=[3,1,5,2]
    print(sol.countMaxOrSubsets(nums))  