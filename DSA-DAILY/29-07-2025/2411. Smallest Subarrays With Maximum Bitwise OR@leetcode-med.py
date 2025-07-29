class Solution:
    def smallestSubarrays(self, nums):
        n = len(nums)
        ans = [1] * n  # initialize answer array with 1s
        for i in range(n):
            x = nums[i]
            for j in range(i - 1, -1, -1):
                if (nums[j] | x) == nums[j]:
                    break
                nums[j] |= x
                ans[j] = i - j + 1
        return ans
if __name__ == "__main__":
    sol = Solution()
    nums = [1, 2, 3, 4]
    print(sol.smallestSubarrays(nums))