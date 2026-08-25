// Question Link: https://leetcode.com/problems/coin-change-ii/description/


// METHOD 1: Recursion --> TLE

class Solution {
public:
    int n;
    int solve(int idx, int amount, vector<int>& coins){
        if(idx >= n){
            return 0;
        }
        if(amount == 0){
            return 1;
        }
      
        int take = 0;
        int not_take = solve(idx+1, amount, coins);
        if(coins[idx] <= amount){
            take = solve(idx, amount - coins[idx], coins);
        }

        return take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();

        return solve(0, amount, coins);
    }
};


// METHOD 2: Memoization

class Solution {
public:
    int n;
    int solve(int idx, int amount, vector<int>& coins, vector<vector<int>> &dp){
        if(idx >= n){
            return 0;
        }
        if(amount == 0){
            return 1;
        }
        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }
        int take = 0;
        int not_take = solve(idx+1, amount, coins, dp);
        if(coins[idx] <= amount){
            take = solve(idx, amount - coins[idx], coins, dp);
        }

        return dp[idx][amount] = take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();

        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));

        return solve(0, amount, coins, dp);
    }
};


// METHOD 3: Bottom UP

class Solution {
public:
    int n;
    int change(int amount, vector<int>& coins) {
        n = coins.size();

        vector<vector<long>> dp(n+1, vector<long> (amount+1, 0));

        for(int amt = 0; amt <= amount; amt++){
            dp[0][amt] = (amt % coins[0] == 0);
        }

        for(int idx = 1; idx < n; idx++){
            for(int amt = 0; amt <= amount; amt++){
                int take = 0;
                int not_take = dp[idx-1][amt];
                if(coins[idx] <= amt){
                    take = dp[idx][amt - coins[idx]];
                }

                dp[idx][amt] = (long)take + not_take;
            }
        }

        return dp[n-1][amount];
    }
};
