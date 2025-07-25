from typing import List

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        s, currs, res = 0, 0, 0
        seen = set()
        for i in nums:
            while i in seen:
                seen.remove(nums[s])
                currs -= nums[s]
                s += 1
            currs += i
            seen.add(i)
            res = max(res, currs)
        return res

if __name__ == "__main__":
    # Take custom input from user
    nums = list(map(int, input("Enter array elements separated by spaces: ").split()))
    sol = Solution()
    result = sol.maximumUniqueSubarray(nums)
    print("Input array:", nums)
    print("Maximum Erasure Value:", result)

    # Sample Output:
    # Enter array elements separated by spaces: 4 2 4 5 6
    # Input array: [4, 2, 4, 5, 6]
    #
