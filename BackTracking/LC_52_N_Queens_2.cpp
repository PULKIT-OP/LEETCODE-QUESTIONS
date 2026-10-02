// Question Link: https://leetcode.com/problems/n-queens-ii/description/


// METHOD 1: Using BackTracking(Recursion)

class Solution {
public:
    bool isValid(int row, int col, int n, vector<string> &board){
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        int i = row-1;
        int j = col+1;
        while(i >= 0 && i < n && j >= 0 && j < n){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j++;
        }

        i = row-1;
        j = col-1;
        while(i >= 0 && i < n && j >= 0 && j < n){
            if(board[i][j] == 'Q'){
                return false;
            }
            j--;
            i--;
        }

        return true;
    }
    void solve(int i, int n, vector<vector<string>> &result, vector<string> &board){
        if(i >= n){
            result.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            if(isValid(i, col, n, board)){
                board[i][col] = 'Q';
                solve(i+1, n, result, board);
                board[i][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        
        solve(0, n, result, board);

        return result.size();
    }
};
