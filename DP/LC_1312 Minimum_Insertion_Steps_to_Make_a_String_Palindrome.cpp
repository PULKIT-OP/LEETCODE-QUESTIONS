// Question Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

// METHOD 1: RECURSION + MEMOIZATION

class Solution {
public:
    int dp[501][501];
    int solve(string &s, int i , int j){
        if(i >= j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int count = 0;
        if(s[i] == s[j]){
            count = solve(s, i+1, j-1);
        }
        else{
            count = 1 + min(solve(s, i+1, j), solve(s, i, j-1));
        }
        return dp[i][j] = count;
    }
    int minInsertions(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, n-1);
    }
};


// METHOD 2: BOTTOM UP ---> BLUE PRINT
// State Define ----> dp[i][j] = minimum insertion to make palindrome from i to j

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
      // if index is same like dp[i][i] ---> means same element which ---> so it will be palindrome ----> which means no addition of element
        for(int i = 0; i < n; i++){
            dp[i][i] = 0;
        }

      // Rest Logic remains same as RECURSION + MEMOIZATION 
        for(int L = 2; L <= n; L++){
            for(int i = 0; i+L-1 < n; i++){
                int j = i + L - 1;

                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};
