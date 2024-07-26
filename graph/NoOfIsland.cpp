#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j) {
        vis[i][j] = 1;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        vector<int> dirRow = {-1, 0, 1, 0};
        vector<int> dirCol = {0, 1, 0, -1};
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int dir = 0; dir < 4; dir++) {
                int nrow = row + dirRow[dir];
                int ncol = col + dirCol[dir];
                
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;  // Handle edge case where the grid is empty

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    bfs(grid, vis, i, j);
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    Solution sol;
    cout << "Number of islands: " << sol.numIslands(grid) << endl;
    return 0;
}
