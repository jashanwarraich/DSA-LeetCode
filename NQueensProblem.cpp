// Q56 https://leetcode.com/problems/n-queens/

// Time: O(N! * N)
// Space: O(N^2)  

class Solution {
private:
    void recf(int col, int n,vector<vector<string>> &ans, vector<string>&board,vector<int> &du, vector<int> &r, vector<int> &dl){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(du[n-1+col-row]==0&&r[row]==0&&dl[row+col]==0){
                board[row][col]='Q';
                du[n-1+col-row]=1;
                r[row]=1;
                dl[row+col]=1;
                recf(col+1,n,ans,board,du,r,dl);
                board[row][col]='.';
                du[n-1+col-row]=0;
                r[row]=0;
                dl[row+col]=0;
            }
        }
        
    }
public:    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> du((2*n)-1,0), r(n,0), dl((2*n)-1,0);
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        
        recf(0,n,ans,board,du,r,dl);
        return ans;
    }
};