// Question Link: https://leetcode.com/problems/minimum-falling-path-sum/description/

// METHOD 1: RECURSION    --->  TLE DEFINITLY

class Solution {
public:
    int n;
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i >= n || i < 0 || j >= n || j < 0){
            return 1e7;
        }
        if(i == n-1){
            return grid[i][j];
        }

        long long downLeft = grid[i][j] + solve(i+1, j-1, grid);
        long long down = grid[i][j] + solve(i+1, j, grid);
        long long downRight = grid[i][j] + solve(i+1, j+1, grid);

        return min({downLeft, down, downRight});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int sum = INT_MAX;
        n = matrix.size();
        for(int j = 0; j < n; j++){
             sum = min(sum , solve(0, j, matrix));
        }

        return sum;
    }
};


// METHOD 2: RECURSION + MEMOIZATION  ---> CAN return TLE because of nothing ---> based on mood of LEETCODE

class Solution {
public:
    int n;
    typedef long long ll;
    int dp[101][101];
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i >= n || i < 0 || j >= n || j < 0){
            return 1e9;
        }
        if(i == n-1){
            return dp[i][j] = grid[i][j];
        }
        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }

        int downLeft = grid[i][j] + solve(i+1, j-1, grid);
        int down = grid[i][j] + solve(i+1, j, grid);
        int downRight = grid[i][j] + solve(i+1, j+1, grid);

        return dp[i][j] = min({downLeft, down, downRight});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int sum = 1e9;
        n = matrix.size();
        for(int i = 0; i <= 100; i++){
            for(int j = 0; j <= 100; j++){
                dp[i][j] = INT_MAX;
            }
        }
        for(int j = 0; j < n; j++){
             sum = min(sum , solve(0, j, matrix));
        }

        return sum;
    }
};


// METHOD 3: BOTTOM UP 

// state definition ---> dp[i][j] ---> total minimum path sum till cell (i, j)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

      // making dp array
        vector<vector<int>> dp(n, vector<int>(n));
      // storing values of first row as we will start from first row
        for(int i = 0; i < n; i++){
            dp[0][i] = matrix[0][i];
        }

      // MAIN BOTTOM UP LOGIC
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                long long topLeft = (long long)matrix[i][j] + (((j-1)>=0) ? dp[i-1][j-1] : INT_MAX);
                long long top = matrix[i][j] + dp[i-1][j];
                long long topRight = (long long)matrix[i][j] + (((j+1)<n) ? dp[i-1][j+1] : INT_MAX);

                dp[i][j] = min({topLeft, top, topRight});
            }
        }

      // finding minimum path sum from last row 
        int ans = INT_MAX;
        for(int j = 0; j < n; j++){
            if(dp[n-1][j] < ans){
                ans = dp[n-1][j];
            }
        }

        return ans;
    }
};
