// Question Link: https://leetcode.com/problems/n-queens/description/


// METHOD 1: Using Recusrion(BackTracking)

class Solution {
public:
  // Checking if A position is valid or not for placing queen
    bool isValid(int row, int col, int n, vector<string> &board){
      // checking vertical column above a cell if it has queen
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        // Right diagonal
        int i = row-1;
        int j = col+1;

        while(i >= 0 && i < n && j >= 0 && j < n){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j++;
        }

        // Left diagonal
        i = row-1;
        j = col-1;
        while(i >= 0 && i < n && j >= 0 && j < n){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }
        
        return true;
    }
    void solve(vector<vector<string>> &result, int i, int n, vector<string> &board){
        // if you crossed last row it means you have placed queens in all previous rows so you have one complete board with n queens in it, push it in result and return from here
        if(i >= n){
            result.push_back(board);
            return;
        }

      // otherwise, at row i you have n columns check which one fits and placce queeen in it and traverse further
        for(int col = 0; col < n; col++){
            if(isValid(i, col, n, board)){
                board[i][col] = 'Q';
                solve(result, i+1, n, board);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;  // to store final all possblilities 
        vector<string> board(n, string(n, '.')); // to store one possibility
        solve(result, 0, n, board);// start with row 0

        return result; // at last return final result whatever is there
    }
};
