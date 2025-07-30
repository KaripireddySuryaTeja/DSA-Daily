class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        res,j,n=0,0,len(nums)
        for i in range(1,n-1):
            if nums[j]<nums[i] and nums[i]>nums[i+1] or nums[j]>nums[i] and nums[i]<nums[i+1]:
                res+=1
                j=i

        return res

# Example usage
#    nums = [2, 4, 1, 1, 6, 5]
if __name__ =="__main__":
    sol=Solution()

    nums = list(map(int,input("Enter the array elements separated by space: ").split()))
    result=sol.countHillValley(nums)
    print("Number of hills and valleys:", result)