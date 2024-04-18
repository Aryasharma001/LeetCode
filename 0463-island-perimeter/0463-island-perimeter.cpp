class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    count += 4; // Count all four sides
                    
                    // Check neighboring cells
                    if(i > 0 && grid[i - 1][j] == 1) count--; // Top
                    if(i < n - 1 && grid[i + 1][j] == 1) count--; // Bottom
                    if(j > 0 && grid[i][j - 1] == 1) count--; // Left
                    if(j < m - 1 && grid[i][j + 1] == 1) count--; // Right
                }
            }
        }
        
        return count;
    }
};
