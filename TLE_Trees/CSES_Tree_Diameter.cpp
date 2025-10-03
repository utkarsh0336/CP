#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> adj[], vector<int>& distance) {
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            distance[neighbor] = distance[node] + 1;
            dfs(neighbor, node, adj, distance);
        }
    }
}

int findDiameter(int n, vector<pair<int, int>>& edges) {
    vector<int> adj[n + 1];
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> distance(n + 1, 0);
    dfs(1, -1, adj, distance);

    int u = max_element(distance.begin(), distance.end()) - distance.begin();
    fill(distance.begin(), distance.end(), 0);
    dfs(u, -1, adj, distance);

    int v = max_element(distance.begin(), distance.end()) - distance.begin();
    return distance[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    cout << findDiameter(n, edges) << "\n";
    return 0;
}