// Question Link: https://leetcode.com/problems/house-robber/

// METHOD 1: Using Recursion ----> TLE aaega LAADLE

class Solution {
public:
    int solve(vector<int> &nums, int i){
        if(i >= nums.size()){
            return 0;
        }

        int skip = solve(nums, i+1);
        int take = nums[i] + solve(nums, i+2);

        return max(skip, take);
    }
    int rob(vector<int>& nums) {

        return solve(nums, 0);
    }
};


// METHOD 2: MEMOIZATION ---> Storing repeating ans in dp array
// As only one variable (i) is changing in recursion function so we will make 1-D DP Array

class Solution {
public:

// Using maximum possible array size according to question
    int dp[101];
    int solve(vector<int> &nums, int i){
        if(i >= nums.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        int skip = solve(nums, i+1);
        int take = nums[i] + solve(nums, i+2);

        return dp[i] = max(skip, take);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};

// METHOD 3: BOTTOM UP 
// Defining state ---> dp[i] = maximum possible sum of money till house i.
// At each house we have two choices either we steal money or we skip that house 
// If we steal current house money ----> We wil have access to the total sum of money of previous to previous house dp[i-2]
// And if we skip current house ----> then we will have access to total sum of money till previous house dp[i-1]

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

      // Defining maximum possible dp array
        vector<int> dp(101);
      // there is no house at 0 so total sum is zero and if we are on house one then we have total sum of nums[0]
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2; i <= n; i++){
            int take = nums[i-1] + dp[i-2];
            int skip = dp[i-1];
            dp[i] = max(take, skip);
        }

        return dp[n];
    }
};
