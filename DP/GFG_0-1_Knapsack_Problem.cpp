// Question Link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1


// METHOD 1: Recursion ---> TLE

class Solution {
  public:
    int n;
    int solve(int idx, vector<int> &val, vector<int> &wt, int W){
        if(idx >= n){
            return 0;
        }
        if(idx == n-1){
            if(W - wt[idx] >= 0){
                return val[idx];
            }
            return 0;
        }
        
        int take = 0;
        int not_take = solve(idx+1, val, wt, W);
        if(wt[idx] <= W){
            take = val[idx] + solve(idx+1, val, wt, W-wt[idx]);
        }
        
        return max(not_take, take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        n = val.size();
        
        return solve(0, val, wt, W);
        
    }
};


// METHOD 2: Memoization

class Solution {
  public:
    int n;
    int solve(int idx, vector<int> &val, vector<int> &wt, int W, vector<vector<int>> &dp){
        if(idx >= n){
            return 0;
        }
        if(idx == n-1){
            if(W - wt[idx] >= 0){
                return val[idx];
            }
            return 0;
        }
        
        if(dp[idx][W] != -1){
            return dp[idx][W];
        }
        
        int take = 0;
        int not_take = solve(idx+1, val, wt, W, dp);
        if(wt[idx] <= W){
            take = val[idx] + solve(idx+1, val, wt, W-wt[idx], dp);
        }
        
        return dp[idx][W] = max(not_take, take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        n = val.size();
        vector<vector<int>> dp(n+1, vector<int> (W+1, -1));
        
        return solve(0, val, wt, W, dp);
        
    }
};


// METHOD 3: BOTTOM UP

class Solution {
  public:
    int n;
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        n = val.size();
        vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
        
        for(int w = wt[0]; w <= W; w++){
            if(wt[0] <= w){
                dp[0][w] = val[0];
            }
        }
        
        for(int idx = 1; idx < n; idx++){
            for(int w = 0; w <= W; w++){
                int take = INT_MIN;
                int not_take = dp[idx-1][w];
                if(wt[idx] <= w){
                    take = val[idx] + dp[idx-1][w - wt[idx]];
                }
                
                dp[idx][w] = max(not_take, take);
            }
        }
        
        return dp[n-1][W];
    }
};


// METHOD 4: Bottom UP

class Solution {
  public:
    int n;
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        n = val.size();
        vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
        
        for(int w = 0; w <= W; w++){
            dp[0][w] = 0;
        }
        for(int idx = 0; idx <= n; idx++){
            dp[idx][0] = 0;
        }
        
        for(int idx = 1; idx <= n; idx++){
            for(int w = 1; w <= W; w++){
                int take = 0;
                int not_take = 0;
                not_take = dp[idx-1][w];
                if(wt[idx-1] <= w){
                    take = val[idx-1] + dp[idx-1][w - wt[idx-1]];
                }
                
                dp[idx][w] = max(not_take, take);
            }
        }
        
        return dp[n][W];
    }
};
