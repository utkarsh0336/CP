#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) {
                dp[i][j] = 0; // already a square
            } else {
                // try vertical cuts
                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
                }
                // try horizontal cuts
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
                }
            }
        }
    }

    cout << dp[a][b] << "\n";
}
