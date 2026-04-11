// Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

// METHOD 1:  RECURRSION - TLE 

class Solution {
public:
    int n;
    int solve(vector<int> &prices, int i, bool bought){
        if(i == n){
            return 0;
        }
        int profit = 0;
        if(!bought){
            int buy = -prices[i] + solve(prices, i+1, true);
            int nothing = 0 + solve(prices, i+1, bought);
            profit = max(buy, nothing);
        }
        else{
            int sell = prices[i] + solve(prices, i+1, false);
            int nothing = 0 + solve(prices, i+1, bought);
            profit = max(sell, nothing);
        }

        return profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        return solve(prices, 0, 0);
    }
};


// MEMOIZAION : 

class Solution {
public:
    int n;
    int dp[30001][2];
    int solve(vector<int> &prices, int i, bool bought){
        if(i == n){
            return 0;
        }

        if(dp[i][bought] != -1){
            return dp[i][bought];
        }
        int profit = 0;
        if(!bought){
            int buy = -prices[i] + solve(prices, i+1, true);
            int nothing = 0 + solve(prices, i+1, bought);
            profit = max(buy, nothing);
        }
        else{
            int sell = prices[i] + solve(prices, i+1, false);
            int nothing = 0 + solve(prices, i+1, bought);
            profit = max(sell, nothing);
        }

        return dp[i][bought] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));

        return solve(prices, 0, 0);
    }
};


// BOTTOM UP - TABULATION : 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        int profit = 0;
        for(int i = n-1; i >= 0; i--){
            for(int bought = 0; bought < 2; bought++){
                if(bought == 0){
                    int buy = -prices[i] + dp[i+1][1-bought];
                    int nothing = 0 + dp[i+1][bought];
                    profit = max(buy, nothing);
                }
                else{
                    int sell = prices[i] + dp[i+1][1-bought];
                    int nothing = 0 + dp[i+1][bought];
                    profit = max(sell, nothing);
                }
                dp[i][bought] = profit;
            }
        }

        return dp[0][0];
    }
};


// METHOD 3: BOTTOM UP SPACE OPTIMIZATION -> We just need previous values nothing else, so we just stored them and used it further then updated them

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int ahead_b = 0;
        int ahead_nb = 0;

        for(int i = n-1; i >= 0; i--){
            int curr_b, curr_nb;
            for(int bought = 0; bought < 2; bought++){
                if(bought == 0){
                    int buy = -prices[i] + ahead_nb;
                    int nothing = 0 + ahead_b;
                    curr_b = max(buy, nothing);
                }
                else{
                    int sell = prices[i] + ahead_b;
                    int nothing = 0 + ahead_nb;
                    curr_nb = max(sell, nothing);
                }
            }
            ahead_b = curr_b;
            ahead_nb = curr_nb;
        }

        return ahead_b;
    }
};
