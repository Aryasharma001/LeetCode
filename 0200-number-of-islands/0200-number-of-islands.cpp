class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        // Check if the cell is out of bounds, already visited, or not part of an island
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || vis[i][j] == 1 || grid[i][j] == '0') {
            return;
        }
        
        vis[i][j] = 1; // Mark the cell as visited

        // Recursively visit adjacent cells
        dfs(i - 1, j, vis, grid); // Up
        dfs(i + 1, j, vis, grid); // Down
        dfs(i, j - 1, vis, grid); // Left
        dfs(i, j + 1, vis, grid); // Right
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();

        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    dfs(i, j, vis, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
