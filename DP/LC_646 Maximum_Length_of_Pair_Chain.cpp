// Question Link: https://leetcode.com/problems/maximum-length-of-pair-chain/


// METHOD 1: USING LIS(DP) ---> Recursive Method   ----> TLE aaega Laadle
// Complete Logic and code remains same, with Little changes
class Solution {
public:
    int solve(vector<vector<int>> &pairs, int i, int prev){
        if(i >= pairs.size()){
            return 0;
        }

        int take = 0;
        int skip = 0;

      // here we have to compare 0th index of second pair and 1st index of first pair
        if(prev == -1 || pairs[i][0] > pairs[prev][1]){
            take = 1 + solve(pairs, i+1, i);
        }
        skip = solve(pairs, i+1, prev);

        return max(take, skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(), pairs.end());

        return solve(pairs, 0, -1);
    }
};


// METHOD 2: RECURSION + MEMOIZATION
// LOGIC REMANS SAME AS LIS ---> just minute syntax changes

class Solution {
public:
    int dp[1001][1001];
    int solve(vector<vector<int>> &pairs, int i, int prev){
        if(i >= pairs.size()){
            return 0;
        }

        if(prev != -1 && dp[i][prev] != -1){
            return dp[i][prev];
        }

        int take = 0;
        int skip = 0;

        if(prev == -1 || pairs[i][0] > pairs[prev][1]){
            take = 1 + solve(pairs, i+1, i);
        }
        skip = solve(pairs, i+1, prev);

        if(prev != -1){
            dp[i][prev] = max(take, skip);
        }

        return max(take, skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        memset(dp, -1, sizeof(dp));

        sort(pairs.begin(), pairs.end());

        return solve(pairs, 0, -1);
    }
};

// METHOD 3: BOTTOM UP 

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int> dp(n, 1);
        sort(pairs.begin(), pairs.end());
        int ans = 1;
        for(int i = 0; i < n; i++){
            int result = 0;
            for(int j = 0; j < n; j++){
              // pairs[j] ---> previous pairs[i] ---> current
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};
