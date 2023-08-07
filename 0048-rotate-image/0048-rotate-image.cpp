class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // If you like the solution PLS UPVOTE
        int s=0;
        int e=matrix.size()-1;
         while(s<e){
            for(int i=0;i<e-s;i++){
                swap(matrix[s][s+i],matrix[e-i][s]);
                swap(matrix[e-i][s],matrix[e][e-i]);
                swap(matrix[e][e-i],matrix[s+i][e]);
             }
            s++;
            e--;
  
        }
        
    }
};