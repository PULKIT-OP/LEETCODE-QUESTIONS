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


// METHOD 4: IN CONSTANT SPACE 
// In this method we will use Bottom up Method as reference Just look at it, in FOR LOOP we have two varialbles skip and take in these variables we have dp[i-2] and dp[i-1] as other variable
// If you just focus on theses dp vairables you will observe these are nothing but previous and previous of previous, of current value, for example if you are on ith house then these are nothing but total values till i-1th and i-2th house.
// So instead of storing these in array you can keep two variables your space will get saved.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // if nums has only one house then it will be the maximum 
        if(n == 1){
            return nums[0];
        }

    // storing previous house as we are starting from house numbder 2
        int prev = nums[0];
    // storing previous to previous house 
        int prev_prev = 0;
        // to store final result
        int result = 0;
        for(int i = 2; i <= n; i++){
            // if you are skipping current house then your curr value will be equal to prev house 
            int skip = prev;
            // if you are taking current house then it means you must have skipped previous house it means you would have stolen prev to prev house so your curr value would be added to that
            int take = nums[i-1] + prev_prev;
            // now store maximum of both values in curr value
            result = max(skip, take);
            // now update prev and prev_prev
            prev_prev = prev;
            prev = result;
        }
    // return final answer
        return result;
    }
};
