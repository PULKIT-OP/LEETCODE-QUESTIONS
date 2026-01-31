// Question Link: https://leetcode.com/problems/minimum-falling-path-sum-ii/description/

// MEHTOD 1: RECURSION

    int n;
    long long solve(int i, int j, vector<vector<int>>& grid){
      // check out of bound
        if(i >= n || i < 0 || j >= n || j < 0){
            return INT_MAX;
        }

      // If reach last row return its value
        if(i == n-1){
            return grid[i][j];
        }

        long long ans = INT_MAX;

      // iterating for each column of next row
        for(int col = 0; col < n; col++){
          // if col of next row equals col of current row (j), just dont calculate it
            if(col == j){
                continue;
            }
            ans = min(ans, solve(i+1, col, grid));
        }

        return grid[i][j] + ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        long long ans = INT_MAX;

      // Finding best path from each cell of first row
        for(int j = 0; j < n; j++){
            ans = min(ans, solve(0, j, grid));
        }

        return ans;
    }
};


// METHOD 2: RECURSION + MEMOIZATION

class Solution {
public:
    int n;
    int dp[201][201];
    long long solve(int i, int j, vector<vector<int>>& grid){
        if(i >= n || i < 0 || j >= n || j < 0){
            return INT_MAX;
        }

        if(i == n-1){
            return grid[i][j];
        }

        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }

        long long ans = INT_MAX;

        for(int col = 0; col < n; col++){
            if(col == j){
                continue;
            }
            ans = min(ans, solve(i+1, col, grid));
        }

        return dp[i][j] = grid[i][j] + ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        long long ans = INT_MAX;

        for(int i = 0; i <= 200; i++){
            for(int j = 0; j <= 200; j++){
                dp[i][j] = INT_MAX;
            }
        }

        for(int j = 0; j < n; j++){
            ans = min(ans, solve(0, j, grid));
        }

        return ans;
    }
};


// METHOD 3: BOTTOM UP

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

      // DP ARRAY 
        vector<vector<int>> dp(n, vector<int> (n));
      // storing first row to start 
        for(int j = 0; j < n; j++){
            dp[0][j] = grid[0][j];
        }

      // iterating 2nd row
        for(int i = 1; i < n; i++){
          // iterating for each column
            for(int j = 0; j < n; j++){
                int mini = INT_MAX;
              // iterating whole column for each column --> of previous row
                for(int k = 0; k < n; k++){
                  // skip the previous column
                    if(k == j){
                        continue;
                    }
                    mini = min(mini, dp[i-1][k]);
                }
              // update dp with minimum value
                dp[i][j] = grid[i][j] + mini;
            }
        }

      // Finding the minimum cost to reach last row
        int ans = INT_MAX;
        for(int j = 0; j < n; j++){
            ans = min(ans, dp[n-1][j]);
        }

        return ans;
    }
};
