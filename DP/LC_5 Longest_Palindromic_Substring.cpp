//Question Link: https://leetcode.com/problems/longest-palindromic-substring/description/

// METHOD 1: RECURSION + MEMOIZATION

class Solution {
public:
    int dp[1001][1001];
    bool isPalindrome(int i, int j, string &s){
        if(i >= j){
            return dp[i][j] = true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == s[j]){
            return dp[i][j] = isPalindrome(i+1, j-1, s);
        }
        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        int n = s.length();

        memset(dp, -1, sizeof(dp));

        int len = -1;
        int sp = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(len < (j-i+1)){
                    if(isPalindrome(i, j, s)){
                        sp = i;
                        len = j-i+1;
                    }
                }
            }
        }

        return s.substr(sp, len);
    }
};


// METHOD 2: BOTTOM UP --->  USING BLUEPRINT

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, false));
        string maxi = "";

        for(int L = 1; L <= n; L++){
            for(int i = 0; (i + L - 1) < n; i++){
                int j = i + L -1;

                if(i == j){
                    dp[i][j] = true;
                    if(maxi.length() < j-i+1){
                        maxi = s.substr(i, j-i+1);
                    }
                }
                else if(i+1 == j){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                        if(maxi.length() < j-i+1){
                            maxi = s.substr(i, j-i+1);
                        }
                    }
                }
                else{
                    if((s[i] == s[j]) && dp[i+1][j-1]){
                        dp[i][j] = true;
                        if(maxi.length() < j-i+1){
                            maxi = s.substr(i, j-i+1);
                        }
                    }
                }
            }
        }

        return maxi;
    }
};
