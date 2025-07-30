class Solution {
    // This method returns the maximum score by removing "ab" or "ba" substrings from s.
    // Each removal of "ab" gives x points, and each removal of "ba" gives y points.
    public int maximumGain(String s, int x, int y) {
        // Always remove the higher scoring substring first
        if (x < y) {
            int t = x;
            x = y;
            y = t;
            s = new StringBuilder(s).reverse().toString();
        }
        int a = 0, b = 0, res = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == 'a') {
                a++;
            } else if (ch == 'b') {
                if (a > 0) {
                    a--;
                    res += x; // Remove "ab"
                } else {
                    b++;
                }
            } else {
                // For any other character, remove as many "ba" as possible
                res += Math.min(a, b) * y;
                a = 0;
                b = 0;
            }
        }
        // Remove remaining "ba" substrings
        res += Math.min(a, b) * y;
        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        // Example input
        String s = "cdbcbbaaabab";
        int x = 4; // Score for removing "ab"
        int y = 5; // Score for removing "ba"

        int result = sol.maximumGain(s, x, y);
        System.out.println("Input string: " + s);
        System.out.println("Score for 'ab': " + x + ", Score for 'ba': " + y);
        System.out.println("Maximum Score: " + result);

        // Sample Output:
        // Input string: cdbcbbaaabab
        // Score for 'ab': 4, Score for 'ba': 5
        // Maximum Score: 19
    }
}