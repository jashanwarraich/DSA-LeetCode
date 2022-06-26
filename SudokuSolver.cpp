// Q57 https://leetcode.com/problems/sudoku-solver/

// Time: O(9^(n ^ 2))
// Space: O(1)

class Solution {
public:
    bool isvalid(int row,int col, vector<vector<char>>&board, char c){
        for(int i=0;i<9;i++){
            if(board[row][i]==c)
                return false;
            if(board[i][col]==c)
                return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                return false;
        }
        return true;
    }
    
    bool recf(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int c='1';c<='9';c++){
                        if(isvalid(i,j,board,c)){
                            board[i][j]=c;
                            if(recf(board)==true)
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

    void solveSudoku(vector<vector<char>>& board) {
        recf(board);
    }
};