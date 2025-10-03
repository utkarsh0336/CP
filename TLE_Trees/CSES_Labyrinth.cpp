/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

// Directions: D, U, R, L
vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
map<pair<int, int>, char> dirChar = {
    {{1, 0}, 'D'}, {{-1, 0}, 'U'}, {{0, 1}, 'R'}, {{0, -1}, 'L'}
};

bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int i, int j,
         vector<vector<char>> &grid,
         vector<vector<bool>> &vis,
         vector<vector<pair<int, int>>> &parent) {
    
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto dir : dirs) {
            int x_ = x + dir[0];
            int y_ = y + dir[1];

            if (isValid(x_, y_, n, m) && !vis[x_][y_] && grid[x_][y_] != '#') {
                vis[x_][y_] = true;
                parent[x_][y_] = {x, y};
                q.push({x_, y_});
            }
        }
    }
}

string getPath(int xs, int ys, int xe, int ye,
               vector<vector<pair<int, int>>> &parent) {
    string path = "";
    int cx = xe, cy = ye;

    while (make_pair(cx, cy) != make_pair(xs, ys)) {
        auto [px, py] = parent[cx][cy];
        int dx = cx - px;
        int dy = cy - py;
        path += dirChar[{dx, dy}];
        cx = px;
        cy = py;
    }

    reverse(path.begin(), path.end());
    return path;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    int xs = -1, ys = -1, xe = -1, ye = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                xs = i;
                ys = j;
            }
            if (grid[i][j] == 'B') {
                xe = i;
                ye = j;
            }
        }
    }

    bfs(xs, ys, grid, vis, parent);

    if (vis[xe][ye]) {
        cout << "YES" << endl;
        string path = getPath(xs, ys, xe, ye, parent);
        cout << path.length() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t = 1;
    // cin >> t;  // Uncomment if multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}
