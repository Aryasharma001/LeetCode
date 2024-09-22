class Solution {
public:
    int func(string text1,string text2,int i ,int j){
        if(i<0 || j<0){
            return 0;
        }
        if(text1[i]==text2[j]){
            return 1+func(text1,text2,i-1,j-1);
        }
        else
            return max(func(text1,text2,i-1,j),func(text1,text2,i,j-1));
                
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};