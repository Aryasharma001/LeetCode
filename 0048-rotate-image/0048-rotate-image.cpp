class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++){
            
            for(int j=0;j<matrix[0].size();j++){
                dp[i][j]=matrix[matrix.size()- j - 1][i];
            }
            
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){

                matrix[i][j]=dp[i][j];
            }
        }

    }
};