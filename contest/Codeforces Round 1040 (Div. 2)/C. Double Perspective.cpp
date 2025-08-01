#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// Structure to represent an edge between two nodes with a weight and index
struct Edge {
    int a, b;         // endpoints of the edge
    long long w;      // weight of the edge (difference b - a)
    int idx;          // original index of the edge (1-based)
};

// Depth-First Search to mark all nodes reachable from 'node'
void dfs(int node, map<int, set<int>> &graph, set<int> &visited) {
    visited.insert(node);
    for (int neighbor : graph[node]) {
        if (!visited.count(neighbor)) {
            dfs(neighbor, graph, visited);
        }
    }
}

// Checks if there is a path between nodes 'a' and 'b' in the current graph
bool isConnected(int a, int b, map<int, set<int>> &graph) {
    set<int> visited;
    dfs(a, graph, visited);
    return visited.count(b) > 0;
}

// Main logic to solve one test case
void solve() {
    int n;
    cin >> n;
    vector<Edge> edges(n);
    int maxNode = 0;

    // Read all edges and calculate their weights
    for (int i = 0; i < n; ++i) {
        cin >> edges[i].a >> edges[i].b;
        edges[i].w = edges[i].b - edges[i].a;
        edges[i].idx = i + 1;
        maxNode = max({maxNode, edges[i].a, edges[i].b});
    }

    // Sort edges by weight in descending order (greedy approach)
    sort(edges.begin(), edges.end(), [](const Edge &x, const Edge &y) {
        return x.w > y.w;
    });

    map<int, set<int>> graph;  // adjacency list for the current graph
    vector<int> result;        // stores indices of selected edges

    // Try to add each edge if it does not create a cycle
    for (const auto &e : edges) {
        if (!isConnected(e.a, e.b, graph)) {
            graph[e.a].insert(e.b);
            graph[e.b].insert(e.a);
            result.push_back(e.idx);
        }
    }

    // Output the number of selected edges and their indices
    cout << result.size() << "\n";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i + 1 < result.size() ? ' ' : '\n');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
