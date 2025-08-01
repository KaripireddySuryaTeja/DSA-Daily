#include <iostream>
#include <deque>
#include <numeric>

// Solves one test case
void solve() {
    int n;
    long long s;
    std::cin >> n >> s;
    std::deque<int> zeros, ones, twos; // Store values by type
    long long s_total = 0; // Sum of all 1's and 2's

    // Read input and classify values
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        if (val == 0)
            zeros.push_back(val);
        else if (val == 1) {
            ones.push_back(val);
            s_total += 1;
        } else {
            twos.push_back(val);
            s_total += 2;
        }
    }

    // If target sum s is less than sum of all 1's and 2's, print original order
    if (s < s_total) {
        std::deque<int> original;
        original.insert(original.end(), zeros.begin(), zeros.end());
        original.insert(original.end(), ones.begin(), ones.end());
        original.insert(original.end(), twos.begin(), twos.end());
        for (int i = 0; i < original.size(); ++i) {
            std::cout << original[i] << (i == original.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
        return;
    }

    long long k = s - s_total; // Difference between target and current sum

    // If difference is exactly 1, print zeros, twos, then ones
    if (k == 1) {
        std::deque<int> result;
        result.insert(result.end(), zeros.begin(), zeros.end());
        result.insert(result.end(), twos.begin(), twos.end());
        result.insert(result.end(), ones.begin(), ones.end());
        for (int i = 0; i < result.size(); ++i) {
            std::cout << result[i] << (i == result.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    } else {
        // Otherwise, output -1 (no valid arrangement)
        std::cout << -1 << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
