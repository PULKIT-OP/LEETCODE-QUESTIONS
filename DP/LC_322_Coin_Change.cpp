// Question Link: https://leetcode.com/problems/coin-change/description/

// METHOD 1: Recursion

class Solution {
public:
    int n;
    int solve(int idx, int amount, vector<int> &coins){
        if(idx == n-1){
            if(amount%coins[idx] == 0){
                return amount/coins[idx];
            }
            return 1e9;
        }

        int not_take = solve(idx+1, amount, coins);
        int take = INT_MAX;
        if(coins[idx] <= amount){
            take = 1 + solve(idx, amount-coins[idx], coins);
        }

        return min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();

        int ans = solve(0, amount, coins);

        if(ans >= 1e9){
            return -1;
        }
        return ans;
    }
};

// METHOD 2: Memoization


class Solution {
public:
    int n;
    int solve(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(idx == n-1){
            if(amount%coins[idx] == 0){
                return amount/coins[idx];
            }
            return 1e9;
        }

        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }

        int not_take = solve(idx+1, amount, coins, dp);
        int take = INT_MAX;
        if(coins[idx] <= amount){
            take = 1 + solve(idx, amount-coins[idx], coins, dp);
        }

        return dp[idx][amount] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();

        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        int ans = solve(0, amount, coins, dp);

        if(ans >= 1e9){
            return -1;
        }
        return ans;
    }
};

// METHOD 3: Bottom up

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));

        // base case
        for(int amt = 0; amt <= amount; amt++){
            if(amt % coins[0] == 0){
                dp[0][amt] = amt/coins[0];
            }
            else{
                dp[0][amt] = 1e9;
            }
        }

        for(int idx = 1; idx < n; idx++){
            for(int amt = 0; amt <= amount; amt++){
                int take = INT_MAX;
                if(coins[idx] <= amt){
                    take = 1 + dp[idx][amt - coins[idx]];
                }
                int not_take = dp[idx-1][amt];

                dp[idx][amt] = min(take, not_take);
            }
        }

        int ans = dp[n-1][amount];
        if(ans >= 1e9){
            return -1;
        }
        return ans;
    }
};
