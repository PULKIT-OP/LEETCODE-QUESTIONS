// Question Link: https://www.geeksforgeeks.org/problems/n-queen-problem0315/1

// METHOD 1:
// Just as normal N-Queen problem, but one extra step --> when we reach last row then instead of pushing directly into result, we have to push col index where we found Q in each row 

class Solution {
  public:
    void pushInResult(vector<vector<int>> &result, vector<string> &board, int n){
        vector<int> temp(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'Q'){
                    temp[i] = j+1;
                }
            }
        }
        
        result.push_back(temp);
    }
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
    void solve(int i, int n, vector<vector<int>> &result, vector<string> &board){
        if(i >= n){
            pushInResult(result, board, n);  // Extra step
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
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> result;
        vector<string> board(n, string(n, '.'));
        
        solve(0, n, result, board);
        
        return result;
    }
};
