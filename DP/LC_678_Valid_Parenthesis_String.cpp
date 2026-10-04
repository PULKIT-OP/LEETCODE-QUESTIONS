// Question Link: https://leetcode.com/problems/valid-parenthesis-string/description


// METHOD 1: Using Recurrsion ----> TLE
// Simple approach ---> at each '*' we have 3 options just explore all three and try to get atleast one true

class Solution {
public:
    int solve(int idx, int open, string &s, int n){
        if(idx == n){
            return open == 0;
        }

        bool isValid = false;
        
        if(s[idx] == '*'){
            isValid |= solve(idx+1, open+1, s, n);
            isValid |= solve(idx+1, open, s, n);
            if(open > 0){
                isValid |= solve(idx+1, open-1, s, n);
            }
        }
        else if(s[idx] == '('){
            isValid |= solve(idx+1, open+1, s, n);
        }
        else if(open > 0){
            isValid |= solve(idx+1, open-1, s, n);
        }

        return isValid;
    }
    bool checkValidString(string s) {
        int n = s.length();

        return solve(0, 0, s, n);
    }
};


// METHOD 2: Using Memoization in above logic

class Solution {
public:
    int dp[101][101];
    int solve(int idx, int open, string &s, int n){
        if(idx == n){
            return open == 0;
        }

        if(dp[idx][open] != -1){
            return dp[idx][open];
        }

        bool isValid = false;
        if(s[idx] == '*'){
            isValid |= solve(idx+1, open+1, s, n);
            isValid |= solve(idx+1, open, s, n);
            if(open > 0){
                isValid |= solve(idx+1, open-1, s, n);
            }
        }
        else if(s[idx] == '('){
            isValid |= solve(idx+1, open+1, s, n);
        }
        else if(open > 0){
            isValid |= solve(idx+1, open-1, s, n);
        }

        return dp[idx][open] = isValid;
    }
    bool checkValidString(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, n);
    }
};


// METHOD 3: Using BOTTOM UP
// t[i][open] --> true/false; String starting from index i having 'open' numbers of open brackets is valid or not; STATE DEFINITION

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();

        vector<vector<int>> dp(n+1, vector<int> (n+1, false));
        dp[n][0] = true;
        for(int i = n-1; i >= 0; i--){
            for(int open = 0; open < n; open++){
                bool isValid = false;
                if(s[i] == '*'){
                    isValid |= dp[i+1][open+1];
                    isValid |= dp[i+1][open];
                    if(open > 0){
                        isValid |= dp[i+1][open-1];
                    }
                }
                else if(s[i] == '('){
                    isValid |= dp[i+1][open+1];
                }
                else if(open > 0){
                    isValid |= dp[i+1][open-1];
                }

                dp[i][open] = isValid;
            }
        }

        return dp[0][0];
    }
};
