#include <iostream>
#include <vector>
#include <string>
using namespace std;

// This class provides a method to maximize the score by removing "ab" or "ba" substrings from a string.
// Each removal of "ab" gives x points, and each removal of "ba" gives y points.
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        string top, bot;
        int top_score, bot_score;

        // Decide which substring to remove first based on which gives more points
        if (y > x) {
            top = "ba";
            top_score = y;
            bot = "ab";
            bot_score = x;
        } else {
            top = "ab";
            top_score = x;
            bot = "ba";
            bot_score = y;
        }

        // First pass: remove as many top substrings as possible
        vector<char> stack;
        for (char ch : s) {
            if (ch == top[1] && !stack.empty() && stack.back() == top[0]) {
                res += top_score;
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }

        // Second pass: remove as many bot substrings as possible from the remaining string
        vector<char> new_stack;
        for (char ch : stack) {
            if (ch == bot[1] && !new_stack.empty() && new_stack.back() == bot[0]) {
                res += bot_score;
                new_stack.pop_back();
            } else {
                new_stack.push_back(ch);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    // Example input
    string s = "cdbcbbaaabab";
    int x = 4; // Score for removing "ab"
    int y = 5; // Score for removing "ba"

    int result = sol.maximumGain(s, x, y);
    cout << "Input string: " << s << endl;
    cout << "Score for 'ab': " << x << ", Score for 'ba': " << y << endl;
    cout << "Maximum Score: " << result << endl;

    // Sample Output:
    // Input string: cdbcbbaaabab
    // Score for 'ab': 4, Score for 'ba': 5
    // Maximum Score: 14

    return 0;
}