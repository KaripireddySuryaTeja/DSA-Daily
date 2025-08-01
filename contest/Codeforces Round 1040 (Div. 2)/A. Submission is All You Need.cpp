#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// A large negative number to represent -infinity for unreachable DP states.
const long long INF = 1e18;

// Solves one test case
void solve() {
    int n;
    cin >> n;
    vector<int> counts(51, 0); // counts[i]: number of times i appears in input
    long long total_sum = 0;   // sum of all input numbers
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        counts[x]++;
        total_sum += x;
    }

    // dp[i][j]: max gain from numbers i..50, given u_{i-1} = j
    // u_{i-1} is the number of times we used (i-1) in previous step
    vector<vector<long long>> dp(52, vector<long long>(n + 1, -INF));

    // Base case: at step 51, no more numbers, so gain is 0.
    for (int j = 0; j <= n; ++j) {
        dp[51][j] = 0;
    }

    // Iterate backwards from i = 50 down to 1.
    for (int i = 50; i >= 1; --i) {
        for (int j = 0; j <= n; ++j) { // j represents u_{i-1}
            dp[i][j] = -INF;
            // Iterate over all possible choices for u_i
            for (int u_i = 0; u_i <= min(j, counts[i]); ++u_i) {
                if (dp[i + 1][u_i] != -INF) {
                    // Calculate current value: using u_i times of i, with cost (1 - i) per use
                    long long current_val = (long long)u_i * (1 - i) + dp[i + 1][u_i];
                    if (dp[i][j] < current_val) {
                        dp[i][j] = current_val;
                    }
                }
            }
        }
    }

    long long max_gain = 0;
    // Final calculation for the total maximum gain
    for (int u_0 = 0; u_0 <= counts[0]; ++u_0) {
        if (dp[1][u_0] != -INF) {
            max_gain = max(max_gain, (long long)u_0 + dp[1][u_0]);
        }
    }

    // Output the answer: original sum plus the maximum gain from DP
    cout << total_sum + max_gain << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
