class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                for(int k=0;k<9;k++){
                    if(board[i][j]==board[i][k] && j!=k && board[i][j]!='.'){
                        //cout<<"Invalid Row: "<<i<<" "<<j<<endl; // Debugging output
                        return false;
                    }
                }
            }
        }
        // Check columns
        for(int j=0;j<9;j++){
            for(int k=0;k<9;k++){
                for(int i=0;i<9;i++){
                    if(board[i][j]==board[k][j] && i!=k && board[i][j]!='.'){
                        //cout<<"Invalid Column: "<<i<<" "<<j<<endl; // Debugging output
                        return false;
                    }
                }
            }
        }
        // Check sub-grids
        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++){
                int hsh[100] = {0}; // Hash table to count occurrence of each number
                for(int i=3*r;i<3*r+3;i++){
                    for(int j=3*c;j<3*c+3;j++){
                        if(board[i][j]!='.'){
                            hsh[int(board[i][j])]++;
                            if(hsh[int(board[i][j])] > 1){
                                //cout<<"Invalid Sub-grid: "<<i<<" "<<j<<endl; // Debugging output
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
