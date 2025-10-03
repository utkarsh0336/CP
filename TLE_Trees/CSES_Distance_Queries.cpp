#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<int> adj[], vector<int> &level, vector<vector<int>> &dp, int l = 0) {
    dp[node][0] = par;
    for (int i = 1; i <= 19; i++) {
        if (dp[node][i - 1] != -1) {
            dp[node][i] = dp[dp[node][i - 1]][i - 1];
        }
    }
    level[node] = l;

    for (auto it : adj[node]) {
        if (it == par) continue;
        dfs(it, node, adj, level, dp, l + 1);
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> adj[n + 1];
    vector<int> level(n + 1, 0);
    vector<vector<int>> dp(n + 1, vector<int>(20, -1));

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, adj, level, dp, 0);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        int A = a, B = b;

        if (level[a] > level[b]) {
            swap(a, b);
        }

        int k = level[b] - level[a];
        b = getKthParent(b, k, dp);

        if (a == b) {
            int ans = (level[A] - level[a]) + (level[B] - level[a]);
            cout << ans << "\n";
            continue;
        }

        for (int i = 19; i >= 0; i--) {
            if (dp[a][i] != -1 && dp[a][i] != dp[b][i]) {
                a = dp[a][i];
                b = dp[b][i];
            }
        }

        int lca = dp[a][0];
        int ans = (level[A] - level[lca]) + (level[B] - level[lca]);
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}