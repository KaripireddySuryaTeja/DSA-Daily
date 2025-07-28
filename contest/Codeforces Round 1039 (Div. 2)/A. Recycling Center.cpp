#include <iostream>
#include <vector>
#include <queue>

void solve() {
    int n;
    long long e;
    std::cin >> n >> e;
    std::vector<long long> a(n);
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (long long weight : a) {
        if (weight > e) {
            min_heap.push(0);
        } else {
            int d = 1;
            long long temp_w = weight;
            while (temp_w <= e / 2) {
                temp_w *= 2;
                d++;
            }
            min_heap.push(d);
        }
    }

    int free_count = 0;
    int time = 1;

    while (!min_heap.empty()) {
        int deadline = min_heap.top();
        min_heap.pop();
        if (time <= deadline) {
            time++;
            free_count++;
        }
    }

    std::cout << n - free_count << std::endl;
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
