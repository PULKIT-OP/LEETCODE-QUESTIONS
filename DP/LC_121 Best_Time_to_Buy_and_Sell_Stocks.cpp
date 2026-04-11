// Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//METHOD 1: Using normal for looop iteration --> why dp??  --> remembering the past

class Solution {
public:
    int n;
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        int mini = prices[0];
        int profit = 0;
        for(int i = 1; i < n; i++){
            profit = max(profit, prices[i] - mini);
            mini = min(mini, prices[i]); // ---> remembering the past
        }

        return profit;
    }
};
