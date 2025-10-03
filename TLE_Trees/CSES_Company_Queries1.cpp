/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<int> adj[], vector<vector<int>> &dp) {
    dp[node][0] = par;
    for (int i = 1; i <= 19; i++) {
        if (dp[node][i - 1] != -1) {
            dp[node][i] = dp[dp[node][i - 1]][i - 1];
        } else {
            dp[node][i] = -1;
        }
    }

    for (auto it : adj[node]) {
        if (it == par) continue;
        dfs(it, node, adj, dp);
    }
}

int getKthParent(int node, int k, vector<vector<int>> &dp) {
    for (int i = 19; i >= 0; i--) {
        if ((k >> i) & 1) {
            if (node == -1) break;
            node = dp[node][i];
        }
    }
    return node;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> adj[n + 1];
    vector<vector<int>> dp(n + 1, vector<int>(20, -1));

    for (int v = 2; v <= n; v++) {
        int u;
        cin >> u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, adj, dp);

    for (int i = 0; i < q; i++) {
        int node, k;
        cin >> node >> k;
        int ans = getKthParent(node, k, dp);
        cout<<ans<<endl;
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}