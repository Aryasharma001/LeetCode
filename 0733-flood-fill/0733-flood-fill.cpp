class Solution {
private:
    void dfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor, int inicolor) {
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        ans[sr][sc] = newColor;
        int n = image.size();
        int m = image[0].size();
        
        // Check neighbors
        for (int i = 0; i < 4; i++) {
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == inicolor && ans[nrow][ncol] != newColor)
                dfs(nrow, ncol, ans, image, newColor, inicolor);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, image, newColor, inicolor);
        return ans;
    }
};
