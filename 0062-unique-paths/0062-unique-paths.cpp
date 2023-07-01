class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp){
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i<1 || j<1)
            return dp[i][j]=0;
        if(i==1 && j==1)
            return dp[i][j]=1;
        int up=f(i-1,j,dp);
        int left=f(i,j-1,dp);
        return dp[i][j]=(up+left);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return f(m,n,dp);
    }
};