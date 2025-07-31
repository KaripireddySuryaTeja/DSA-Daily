from typing import List
class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        res=set()
        for i in range(0,len(arr)):
            res.add(arr[i])
            for j in range(i-1,-1,-1):
                if(arr[j]==(arr[j]|arr[i])):
                    break
                arr[j]|=arr[i]
                res.add(arr[j])
        return len(res)        

if __name__ == "__main__":
    arr = list(map(int, input("Enter an array of numbers separated by spaces: ").split()))
    solution = Solution()
    result = solution.subarrayBitwiseORs(arr)
    print("Number of distinct bitwise ORs:", result)