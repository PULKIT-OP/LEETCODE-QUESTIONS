// Question Link: https://leetcode.com/problems/palindrome-partitioning/description/

// METHOD 1: USING DP ---> USING SUBSTRING BLUEPRINT ---> Although it also uses backtracking concept a little bit

class Solution {
public:
    void solve(string &s, int i, vector<vector<bool>> &dp, vector<string> &currPart, vector<vector<string>> &result){
      // If your index i gets out of bound means you traversed through all the elements so it means you are good to go to insert all the elements you found in result
        if(i >= s.length()){
            result.push_back(currPart);
            return;
        }

      // Otherwise, traverse through ith index to last index and check 
        for(int j = i; j < s.length(); j++){
          // if ith index to jth index is a palindrome
            if(dp[i][j] == true){
              // Then push that substring in current elements array, then check from j+1th index
                currPart.push_back(s.substr(i, j-i+1));
                solve(s, j+1, dp, currPart, result);
              // After checking till last from this index remove the element you pushed in current array  ---->  This thing is also known as BACKTRACKING
                currPart.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();

      // In starting we are just filling up the dp array to store palindromes from ith index to jth index
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }

        for(int L = 2; L <= n; L++){
            for(int i = 0; (i+L-1) < n; i++){
                int j = i+L-1;
                if(i == j){
                    dp[i][j] = true;
                }
                if(i+1 == j){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    dp[i][j] = ((s[i] == s[j]) && dp[i+1][j-1]);
                }
            }
        }

      // Now make a result array to store final result
        vector<vector<string>> result;
      // Now make a array to store current elements which are elegible
        vector<string> currPart;
        solve(s, 0, dp, currPart, result);

        return result;
    }
};


// MEHTOD 2: USING BACKTRACKING
