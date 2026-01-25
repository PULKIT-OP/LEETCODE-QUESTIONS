// Question Link: https://leetcode.com/problems/unique-paths/description/


// METHOD 1: RECURSION ---> TLE aaega LAADLE

class Solution {
public:
    int solve(int i, int j, int m, int n){
        if(i > m || j > n){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        int down = solve(i+1, j, m, n);
        int right = solve(i, j+1, m, n);

        return down + right;
    }
    int uniquePaths(int m, int n) {
        return solve(0, 0, m, n);
    }
};


// METHOD 2: MEMOIZATION

class Solution {
public:
    int dp[101][101];
    int solve(int i, int j, int m, int n){
        if(i > m || j > n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == m-1 && j == n-1){
            return dp[i][j] = 1;
        }
        int down = solve(i+1, j, m, n);
        int right = solve(i, j+1, m, n);

        return dp[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {

        memset(dp, -1, sizeof(dp));
        
        return solve(0, 0, m, n);
    }
};


// METHOD 3: BOTTOM UP

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        for(int i = 1; i < m; i++){
            dp[i][0] = 1;
        }
        for(int j = 1; j < n; j++){
            dp[0][j] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};


// METHOD 4: MATHEMATICAL APPROCH    ----->   BEST FOR INTERVIEWS  --->   only after too much pressure

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m-1 + n-1;
        int r = min(m-1, n-1);

        long long res = 1;

        for(int i = 1; i <= r; i++){
            res = res * (N - r + i) / i;
        }

        return res;

    }
};
