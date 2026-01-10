// Question Link: https://leetcode.com/problems/longest-increasing-subsequence/


// METHOD 1: RECURSION APPROACH ----> TLE aaega LAADLE
// Here logic is simple ---> Suppose you are on ith index if your previous element is smaller than you then you are forming LONGEST INCREASING SUBSEQUENCE so add 1 in your answer.
// If you are smaller than your previous than leave it ----> these two things was for if you want to take 
// But if you want to skip ----> just call recursion for next element and dont change your previous element CUZ you didnot altered sequence in any sense

class Solution {
public:
    int solve(vector<int> &nums, int i, int prev){
        if(i >= nums.size()){
            return 0;
        }

        int take = 0; 
        int skip = 0;
        if(prev != -1 || nums[i] > nums[prev]){
            take = 1 + solve(nums, i+1, i);
        }
        skip = solve(nums, i+1, prev);

        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }

        return solve(nums, 0, -1);
    }
};


// METHOD 2: MEMOIZATION
// Here we have same logic
//
class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &nums, int i, int prev){
        if(i >= nums.size()){
            return 0;
        }
        
        if(prev != -1 && dp[i][prev] != -1){
            return dp[i][prev];
        }

        int take = 0; 
        int skip = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + solve(nums, i+1, i);
        }
        skip = solve(nums, i+1, prev);

        if(prev != -1){
            dp[i][prev] = max(take, skip);
        }

        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        dp.resize(n+1, vector<int> (n+1, -1));

        return solve(nums, 0, -1);
    }
};


// METHOD 3: BOTTOM UP ---> Here Approach towards ques is little different ---> n^2
// Here we are making 1-D dp array but we are storing length of maximum LIS till ith index 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
      // initializing dp array
        vector<int> dp(n, 1);
      // for storing maximum LIS 
        int maxi = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
              // ith index means that index till which you want to calculate maximum LIS possible
              // so when you are comparing nums[i] and nums[j] you want to check numbers smaller before i
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxi = max(dp[i], maxi);
                }
            }
        }
        return maxi;
    }
};
