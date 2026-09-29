// Question Link: https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/description/


// METHOD 1: 

class Solution {
public:
    int n;
    int m;
    int dp[101][101][203];
    bool solve(int i, int j, int balance, vector<vector<char>>& grid){
        if(i >= m || i < 0 || j >= n || j < 0){
            return false;
        }
        if(grid[i][j] == '('){
            balance++;
        }
        else if(grid[i][j] == ')'){
            balance--;
        }
        if(balance < 0){
            return false;
        }

        if(dp[i][j][balance] != -1){
            return dp[i][j][balance];
        }

        if((i == m-1 && j == n-1) && (balance > 0 || balance < 0)){
            return false;
        }
        else if(i == m-1 && j == n-1 && balance == 0){
            return true;
        }

        int down = solve(i+1, j, balance, grid);
        int right = solve(i, j+1, balance, grid);

        return dp[i][j][balance] = down | right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if(grid[0][0] == ')'){
            return false;
        }

        if((m+n-1)%2 != 0){
            return false;
        }

        if(grid[m-1][n-1] == '('){
            return false;
        }

        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 101; j++){
                for(int k = 0; k < 203; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(0, 0, 0, grid);
    }
};
