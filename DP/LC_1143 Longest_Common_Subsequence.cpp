// Question Link: https://leetcode.com/problems/longest-common-subsequence/

// METHOD 1: RECURSION ---> TLE AAEGA LAADLE

class Solution {
public:
    int solve(int x, int y, string &text1, string &text2){
        if(x >= text1.length() || y >= text2.length()){
            return 0;
        }

        if(text1[x] == text2[y]){
            return 1 + solve(x+1, y+1, text1, text2);
        }
        
        int remove_1 = solve(x+1, y, text1, text2);
        int remove_2 = solve(x, y+1, text1, text2);

        return max(remove_1, remove_2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        return solve(0, 0, text1, text2);
    }
};


// METHOD 2: RECURSION + MEMOIZATION

class Solution {
public:
    int n;
    int m;
    int dp[1001][1001];
    int solve(int x, int y, string &text1, string &text2){
        if(x >= n || y >= m){
            return 0;
        }
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        if(text1[x] == text2[y]){
            return dp[x][y] = 1 + solve(x+1, y+1, text1, text2);
        }
        
        int remove_1 = solve(x+1, y, text1, text2);
        int remove_2 = solve(x, y+1, text1, text2);

        return dp[x][y] = max(remove_1, remove_2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.length();
        m = text2.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, text1, text2);
    }
};


// BOTTOM UP ---> OPTIMIZED APPROACH

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

      // STATE DEFINITION ---> dp[i][j] ---> LCS of lenght i of s1 and length j of s2
        vector<vector<int>> dp(n+1, vector<int> (m+1));
        for(int i = 0; i < n; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j < m; j++){
            dp[0][j] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};


// IF YOU WANT TO PRINT THE LONGEST COMMON STRING ----> 

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n+1, vector<int> (m+1));
        for(int i = 0; i < n; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j < m; j++){
            dp[0][j] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

      // THIS PART IS ONLY IF YOU WANT TO PRINT THE COMMON PART
        vector<char> result;
        int i = n;
        int j = m;
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                    result.push_back(s1[i-1]);
                    i--;
                    j--;
                }
                else{
                    if(dp[i-1][j] > dp[i][j-1]){
                        i--;
                    }
                    else{
                        j--;
                    }
                }
        }

      // AS WE STORED IN REVERSE ORDER WE HAVE TO REVERSE IT AGAIN BEFORE PRINTING
        reverse(result.begin(), result.end());
      // NOW PRINTING THE RESULT
        for(int k = 0; k < result.size(); k++){
            cout << result[k];
        }

      // Just return the Longest Common Sequence if it is asked and Leave the previous Printing Part
        return dp[n][m];
    }
};
