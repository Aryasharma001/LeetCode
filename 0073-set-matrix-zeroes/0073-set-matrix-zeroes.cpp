class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>rows;
        vector<int>cols;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for(int i=0;i<rows.size();i++){
            for(int j=0;j<n;j++){
                matrix[rows[i]][j]=0;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<cols.size();j++){
                matrix[i][cols[j]]=0;
            }
        }
        
        
    }
};