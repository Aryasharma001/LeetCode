class Solution {
public:
    void dfs(int i,int j, vector<vector<int>> &grid,int &count,vector<vector<int>> & vis){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]==1){
            return;
        }
        count++;
        vis[i][j]=1;
        dfs(i-1,j,grid,count,vis);
        dfs(i,j+1,grid,count,vis);
        dfs(i,j-1,grid,count,vis);
        dfs(i+1,j,grid,count,vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    int c=0;
                    dfs(i,j,grid,c,vis);
                    count=max(count,c);
                }
            }
        }
        return count;
    }
};