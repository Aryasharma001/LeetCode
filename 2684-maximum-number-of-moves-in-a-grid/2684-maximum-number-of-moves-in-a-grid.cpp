class Solution {
public:
    int moves(vector<vector<int>>& grid, int i, int j,vector<vector<int>>&memo) {
        if(i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }
        if(memo[i][j]!=-1) return memo[i][j];
        
    
        
    int diagonal_up = 0, down = 0, diagonal_down = 0;

    // Check each possible direction independently
    if(i - 1 >= 0 && j + 1 < grid[0].size() && grid[i-1][j+1] > grid[i][j]) {
        diagonal_up = moves(grid, i-1, j+1,memo);
    }
    if(j + 1 < grid[0].size() && grid[i][j+1] > grid[i][j]) {
        down = moves(grid, i, j+1,memo);
    }
    if(i + 1 < grid.size() && j + 1 < grid[0].size() && grid[i+1][j+1] > grid[i][j]) {
        diagonal_down = moves(grid, i+1, j+1,memo);
    }

    return memo[i][j]=max({diagonal_up, diagonal_down, down}) + 1;
}

    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int movesMax=0;
        vector<vector<int>>memo(n,vector<int>(m,-1));
         for(int i = 0; i < grid.size(); i++) {
            movesMax = max(movesMax, moves(grid, i, 0,memo) - 1);
        }
        return movesMax;
    }
};