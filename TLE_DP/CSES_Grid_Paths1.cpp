#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n;
vector<string> grid;
vector<vector<int>> dp;

int count_paths(int i, int j) {
    if(i >= grid.size() || j >= grid[0].size()) return 0;
    if(grid[i][j] == '*') return 0;
    if(i == grid.size()-1 && j == grid[0].size()-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    int down = count_paths(i+1,j);
    int right = count_paths(i,j+1);

    return dp[i][j] = (down + right) % mod;
}

int main() {
    cin >> n;
    grid.resize(n);
    dp.assign(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    cout << count_paths(0,0) << endl;
    return 0;
}
