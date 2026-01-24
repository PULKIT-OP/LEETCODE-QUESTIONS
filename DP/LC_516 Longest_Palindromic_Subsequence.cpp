// Question Link: https://leetcode.com/problems/longest-palindromic-subsequence/description/

// METHOD 1: RECURSION + MEMOIZATION  --->  USING LCS(Longest Common Subsequence)

class Solution {
public:
    int dp_2[1001][1001];
    int n;
    int maxi;
    int solve(string &s1, string &s2, int i, int j){
        if(i >= n || j >= n){
            return 0;
        }
        if(dp_2[i][j] != -1){
            return dp_2[i][j];
        }
        if(s1[i] == s2[j]){
            return dp_2[i][j] = 1 + solve(s1, s2, i+1, j+1);
        }
        else{
            int remove_i = solve(s1, s2, i+1, j);
            int remove_j = solve(s1, s2, i, j+1);

            return dp_2[i][j] = max(remove_i, remove_j);
        }

        return -1;
    }
    int longestPalindromeSubseq(string s) {
        n = s.length();
        string s2 = s;

        reverse(s2.begin(), s2.end());

        memset(dp_2, -1, sizeof(dp_2));

        maxi = -1;
        
        return solve(s, s2, 0, 0);
    }
};


// METHOD 2: BOTTOM UP  --->  USING LPS BLUE-PRINT

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int> (n));

        // We know all the letters will have lenght 1 of subsequence of itself
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }

        // We stored length 1 of subsequence so, now we will start subsequence with length 2
        for(int LEN = 2; LEN <= n; LEN++){
            for(int i = 0; i+LEN-1 < n; i++){
                int j = i+LEN-1;
                // if ith and jth letters are same then the subsequence length will increase by 2 ----> because two new letters will be added
                if(s[i] == s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                // Otherwise check for other possible options
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        // return the total subsequence which is asked ---> here 0 to n
        return dp[0][n-1];
    }
};
