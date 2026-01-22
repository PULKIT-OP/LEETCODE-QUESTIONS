// Question Link: https://leetcode.com/problems/edit-distance/description/

// METHOD 1: Using RECURSION --->

class Solution {
public:
    int m;
    int n;

    int solve(string &s1, string &s2, int i, int j){
        if(i >= m){
            return n-j;
        }
        else if(j >= n){
            return m-i;
        }

        if(s1[i] == s2[j]){
            return solve(s1, s2, i+1, j+1);
        }
        else{
            int insert = 1 + solve(s1, s2, i, j+1);
            int del    = 1 + solve(s1, s2, i+1, j);
            int replace = 1 + solve(s1, s2, i+1, j+1);

            return min({insert, del, replace});
        }

        return -1;
    }
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();

        return solve(word1, word2, 0, 0);
    }
};


// METHOD 2: RECURSION + MEMOIZATION ----> There are two ways to do this ----> either you choose from TOP to BOTTOM or BOTTOM to TOP

// TRAVERSING FROM FIRST NODE TO LAST NODE
class Solution {
public:
    int m;
    int n;

    int dp[501][501];

    int solve(string &s1, string &s2, int i, int j){
        if(i >= m){
            return n-j;
        }
        else if(j >= n){
            return m-i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            return dp[i][j] = solve(s1, s2, i+1, j+1);
        }
        else{
            int insert  = 1 + solve(s1, s2, i, j+1);
            int del     = 1 + solve(s1, s2, i+1, j);
            int replace = 1 + solve(s1, s2, i+1, j+1);

            return dp[i][j] = min({insert, del, replace});
        }

        return -1;
    }
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();

        memset(dp, -1, sizeof(dp));

        return solve(word1, word2, 0, 0);
    }
};


// TRAVERSING FROM LAST NODE TO FIRST NODE
class Solution {
public:
    int m;
    int n;

    int dp[501][501];

    int solve(string &s1, string &s2, int i, int j){
        if(i == 0 || j == 0){
            return i+j;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = solve(s1, s2, i-1, j-1);
        }
        else{
            int insert = 1 + solve(s1, s2, i, j-1);
            int del    = 1 + solve(s1, s2, i-1, j);
            int replace = 1 + solve(s1, s2, i-1, j-1);

            return dp[i][j] = min({insert, del, replace});
        }

        return -1;
    }
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();

        memset(dp, -1, sizeof(dp));

        return solve(word1, word2, m, n);
    }
};


// METHOD 3: BOTTOM UP ----> JUST LIKE MEMOIZATON FROM TOP TO BOTTOM

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i = 0; i <= m; i++){
            dp[i][0] = i;
        }
        for(int j = 0; j <= n; j++){
            dp[0][j] = j;
        }

        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = i + j;
                }

                else if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int insert = 1 + dp[i][j-1];
                    int del    = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];

                    dp[i][j] = min({insert, del, replace});
                }
            }
        }

        return dp[m][n];
    }
};
