class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        """
        Returns the maximum score by removing "ab" or "ba" substrings from s.
        Each removal of "ab" gives x points, and each removal of "ba" gives y points.
        Always remove the higher scoring substring first.
        """
        if x < y:
            s = s[::-1]
            x, y = y, x
        a, b, res = 0, 0, 0
        for c in s:
            if c == 'a':
                a += 1
            elif c == 'b':
                if a > 0:
                    a -= 1
                    res += x  # Remove "ab"
                else:
                    b += 1
            else:
                # For any other character, remove as many "ba" as possible
                res += min(a, b) * y
                a, b = 0, 0
        # Remove remaining "ba" substrings
        res += min(a, b) * y
        return res

if __name__ == "__main__":
    sol = Solution()
    # Example input
    s = "cdbcbbaaabab"
    x = 4  # Score for removing "ab"
    y = 5  # Score for removing "ba"

    result = sol.maximumGain(s, x, y)
    print("Input string:", s)
    print("Score for 'ab':", x, ", Score for 'ba':", y)
    print("Maximum Score:", result)

    # Sample Output: 19
    # Input string: cdbcbbaaabab
    # Score for 'ab': 4 , Score for 'ba': 5