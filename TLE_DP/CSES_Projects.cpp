/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;
 
long long solve(int idx, vector<vector<int>> &arr, vector<long long> &dp) {
    if (idx >= arr.size()) return 0;
    if (dp[idx] != -1) return dp[idx];
 
    // Find the next project that starts after current project's end day
    int nextIdx = lower_bound(arr.begin(), arr.end(), arr[idx][1] + 1,
                               [](const vector<int> &v, int val) {
                                   return v[0] < val;
                               }) - arr.begin();
 
    long long take = arr[idx][2] + solve(nextIdx, arr, dp);
    long long skip = solve(idx + 1, arr, dp);
 
    return dp[idx] = max(take, skip);
}
 
void Solve() {
    int n;
    cin >> n;
 
    vector<vector<int>> arr(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
 
    // Sort by start time
    sort(arr.begin(), arr.end());
 
    vector<long long> dp(n, -1);
    cout << solve(0, arr, dp) << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    Solve();
    return 0;
}
