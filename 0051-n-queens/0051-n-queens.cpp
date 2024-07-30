class Solution {
public:
    bool isSafe(int row,int col, vector<string>& board,int n){
        int dupR=row;
        int dupC=col;
        
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return 0;
            }
            row--;
            col--;
        }
        row=dupR;
        col=dupC;
        
        while(col>=0){
             if(board[row][col]=='Q'){
                return 0;
            }
            
            col--;
        }
        row=dupR;
        col=dupC;
        
        while(col>=0 && row<n){
             if(board[row][col]=='Q'){
                return 0;
            }
            row++;
            col--;
        }
        return 1;
    }
    
    
    void f(int col , vector<vector<string>>& ans,vector<string>& board,int n){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                f(col+1,ans,board,n);
                board[row][col]='.';
            }
        }
    }
    
    
    
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        
        f(0,ans,board,n);
        return ans;
    }
};