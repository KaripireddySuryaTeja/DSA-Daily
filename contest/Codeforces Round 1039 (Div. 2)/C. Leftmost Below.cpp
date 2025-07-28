#include <iostream>
#include <vector>
#include <set>

void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    std::multiset<long long> ms;
    ms.insert(b[0]);
    bool possible = true;

    for (int i = 1; i < n; ++i) {
        long long min_prev = *ms.begin();
        if (b[i] >= 2 * min_prev) {
            possible = false;
            break;
        }
        ms.insert(b[i]);
    }

    std::cout << (possible ? "YES\n" : "NO\n");
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
