class Solution {
public:
    
    bool is_safe(int row,int col,vector<string>board,int n){
        int duprow=row;
        int dupcol=col;
        while(duprow>=0 && dupcol>=0){
            if(board[duprow][dupcol]=='Q')
                return false;
            duprow--;
            dupcol--;
        }
        dupcol=col;
        //check horizontal straingt
        while(dupcol>=0){
            if(board[row][dupcol]=='Q')
                return false;
            dupcol--;
        }
        dupcol=col;
        duprow=row;
        while(duprow<n && dupcol>=0){
            if(board[duprow][dupcol]=='Q')
                return false;
            duprow++;
            dupcol--;
        }
        return true;

    }
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        
        for(int row=0;row<n;row++){
            if(is_safe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
        }
            
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        vector<vector<string>>ans;
        solve(0,board,ans,n);
        return ans;
    }
};