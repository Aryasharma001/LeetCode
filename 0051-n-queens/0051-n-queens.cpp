class Solution {
public:
    bool isValid(int i, int j, vector<string>& board, int n) {
    // Check for another queen in the same row
    for (int col = 0; col < n; col++) {
        if (board[i][col] == 'Q' && col != j)
            return false;
    }

    // Check for queens in the upper-left diagonal
    for (int row = i, col = j; row >= 0 && col >= 0; row--, col--) {
        if (board[row][col] == 'Q')
            return false;
    }

    // Check for queens in the lower-left diagonal
    for (int row = i, col = j; row < n && col >= 0; row++, col--) {
        if (board[row][col] == 'Q')
            return false;
    }

    return true;
}

    void playing(vector<string>&board,int n,vector<vector<string>>&ans,int j){
        if(j==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(i,j,board,n)){
                board[i][j]='Q';
                playing(board,n,ans,j+1);
                board[i][j]='.';
        }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++)
            board[i]=s;
        
        vector<vector<string>>ans;

        playing(board,n,ans,0);
        return ans;
    }
};