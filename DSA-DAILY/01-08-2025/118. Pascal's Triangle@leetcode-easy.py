from typing import List
class Solution:
    def generate(self, num: int) -> List[List[int]]:
        dp=[[1]]
        for i in range(2,num+1):
            dp.append([1]+[dp[-1][j]+dp[-1][j+1]for j in range(i-2)]+[1])
        return dp
if __name__ == "__main__":
    sol=Solution()
    n=int(input("Enter the number of rows for Pascal's Triangle:"))
    res=sol.generate(n)
    for row in res:
        print(row)