// Question Link: https://leetcode.com/problems/unique-paths-ii/description/

// METHOD 1: Using Recursion:

class Solution {
public:
    int m;
    int n;
    int solve(vector<vector<int>> &grid, int i, int j){
        if(i >= m || j >= n){
            return 0;
        }
        if(grid[i][j] == 1){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }

        int down = solve(grid, i+1, j);
        int right = solve(grid, i, j+1);

        return down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        return solve(obstacleGrid, 0, 0);
    }
};


// METHOD 2: USING RECURSION + MEMOIZATION

class Solution {
public:
    int m;
    int n;
    int dp[101][101];
    int solve(vector<vector<int>> &grid, int i, int j){
        if(i >= m || j >= n){
            return 0;
        }
        if(grid[i][j] == 1){
            return dp[i][j] = 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == m-1 && j == n-1){
            return 1;
        }

        int down = solve(grid, i+1, j);
        int right = solve(grid, i, j+1);

        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(obstacleGrid, 0, 0);
    }
};


// METHOD 3: BOTTOM UP

// Thsi version is not recommended ----> LOTS OF IF ELSE CONDITIONS. INSTEAD USE BETTER VERSION OF BOTTOM UP WHICH IS BELOW THIS

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] == 0){
                dp[i][0] = 1;
            }
            else{
                break;
            }
        }
        for(int j = 0; j < n; j++){
            if(obstacleGrid[0][j] == 0){
                dp[0][j] = 1;
            }
            else{
                break;
            }
        }

        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]){
            return 0;
        }


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i-1 >= 0 && j-1 >= 0){
                    if(obstacleGrid[i-1][j] == 0 && obstacleGrid[i][j-1] == 0){
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                    else if(obstacleGrid[i][j-1] == 0){
                        dp[i][j] = dp[i][j-1];
                    }
                    else if(obstacleGrid[i-1][j] == 0){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
        }

        return dp[m-1][n-1];

    }
};


// Later I came up with this updated version with minimum conditions ----> ALL YOU HAVE TO DO IS JUST TRUST DP BLINDLY 

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] == 0){
                dp[i][0] = 1;
            }
            else{
                break;
            }
        }
        for(int j = 0; j < n; j++){
            if(obstacleGrid[0][j] == 0){
                dp[0][j] = 1;
            }
            else{
                break;
            }
        }

        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]){
            return 0;
        }


        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];

    }
};
