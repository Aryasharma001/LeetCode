class Solution {
public:
    bool solve(vector<vector<char>>&board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(valid(board,i,j,c)){
                            board[i][j]=c;
                            
                            if(solve(board)==true)
                                return true;
                            else
                                board[i][j]='.';
                        }
                    }
                    return false;
                        
                }
            }
        }
        return true;
    }
    
    bool valid(vector<vector<char>>&board,int i ,int j , char c){
        for(int t=0;t<9;t++){
            if(board[t][j]==c)
                return false;
            if(board[i][t]==c)
                return false;
            if(board[3*(i/3)+t/3][3*(j/3)+t%3]==c)
                return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};