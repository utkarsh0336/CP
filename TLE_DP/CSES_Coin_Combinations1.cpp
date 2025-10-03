/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// dp[sum] = number of ways to make sum
int solve(int sum, vector<int> &a, vector<int> &dp) {
    if (sum == 0) return 1;
    if (sum < 0) return 0;
    if (dp[sum] != -1) return dp[sum];

    long long ways = 0;
    for (int i = 0; i < a.size(); i++) {
        ways = (ways + solve(sum - a[i], a, dp)) % mod;
    }

    return dp[sum] = ways;
}

void solve1() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(x + 1, -1);
    cout << solve(x, a, dp) << endl;
}

int main() {
    int t = 1;
    while (t--) {
        solve1();
    }
    return 0;
}
