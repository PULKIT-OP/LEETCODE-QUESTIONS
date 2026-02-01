// Question Link: https://leetcode.com/problems/partition-equal-subset-sum/description/

// METHOD 1: RECURSION ---> USING KNAPSAK ---> TLE CONFIRMED

class Solution {
public:
    int n;
    bool solve(int i, vector<int> &nums, int target){
      // if your target reached 0 means you got your subset so return true
        if(target == 0){
            return true;
        }
      // if you overflow means you didnot reached to your ans so return false
        if(i >= n){
            return false;
        }

      // take two variables take and skip
        bool take = false;
        bool skip = false;
      // if target is greater or equal to nums[i] ---> then only check for take --> because we neet positive value of target for next iteration
        if(target >= nums[i]){
            take = solve(i+1, nums, target - nums[i]);
        }
      // other wise skip --> target reamains same as you skipped current index
        skip = solve(i+1, nums, target);

      // return or of take ans skip
        return take || skip;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();

      // if total sum is even only then it is possible to break nums in two subsets 
        int total_sum = 0;
        for(int i = 0; i < n; i++){
            total_sum += nums[i];
        }

      // if total sum is not even return false 
        if(total_sum % 2 != 0){
            return false;
        }

        return solve(0, nums, total_sum/2);
    }
};


// METHOD 2: USING RECURSION + MEMOIZATION
// SAME LOGIC JUST MEMOIZED VERSION

class Solution {
public:
    int n;
    int dp[201][10001]; // --->  i --> maximum range is 200 as per ques, j --> took bigger value as target can be large
    bool solve(int i, vector<int> &nums, int target){
        if(target == 0){
            return true;
        }
        if(i >= n){
            return false;
        }

        if(dp[i][target] != -1){
            return dp[i][target];
        }

        bool take = false;
        bool skip = false;
        if(target >= nums[i]){
            take = solve(i+1, nums, target - nums[i]);
        }
        skip = solve(i+1, nums, target);

        return dp[i][target] = take || skip;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int total_sum = 0;
        for(int i = 0; i < n; i++){
            total_sum += nums[i];
        }

        if(total_sum % 2 != 0){
            return false;
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, nums, total_sum/2);
    }
};


// METHOD 3: BOTTOM UP 
// FIRST MEHTOD ---> 2D dp

class Solution {
public:
    int n;
    bool solve(vector<int> &nums, int total){
      // Make a 2d dp array to store values
        vector<vector<bool>>dp(n+1, vector<bool>(total+1, 0));
      // from recursion we know if target is zero --> result is true
      // here jth index represents target
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }

      // from recursion we know if, ith index reached n it is out of bound so iterate from n-1 to 0
        for(int i = n-1; i >= 0; i--){
          // iterate j(target) from 0 to total/2 ---> as we just need to check for half value
            for(int j = 0; j <= total/2; j++){
                bool take = false;
              // checking then because we cant take -ve value of target(j)
                if(j >= nums[i]){
                  // if you are taking then you will decrease value of target(j) by nums[i] as we did in recursion
                    take = dp[i+1][j - nums[i]];
                }
              // otherwise just increment i
                bool skip = dp[i+1][j];

              // fill dp[i][j] with take || skip
                dp[i][j] = take || skip;
            }
        }

      // returning this because we need if we get subarray from index 0 to total/2
        return dp[0][total/2];
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();

      // initial logic of even and odd sum remains same
        int total_sum = 0;
        for(int i = 0; i < n; i++){
            total_sum += nums[i];
        }

        if(total_sum % 2 != 0){
            return false;
        }

        int x = total_sum/2;

      // if total sum is even then call solve function 
        return solve(nums, total_sum);
    }
};

// SECOND METHOD ---> 2 1d dp ---> SPACE OPTIMIZATION
// from above mentioned bottom up we can see that ---> we just need current row and next row for iteration

class Solution {
public:
    int n;
    bool solve(vector<int> &nums, int total){
        vector<int> curr(total+1, 0);
        vector<int> next(total+1, 0);
        curr[0] = 1;
        next[0] = 1;

        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <= total/2; j++){
                bool take = false;
                if(j >= nums[i]){
                    take = next[j - nums[i]];
                }
                bool skip = next[j];

                curr[j] = take || skip;
            }
            next = curr;
        }

        return next[total/2];
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int total_sum = 0;
        for(int i = 0; i < n; i++){
            total_sum += nums[i];
        }

        if(total_sum % 2 != 0){
            return false;
        }

        int x = total_sum/2;

        return solve(nums, total_sum);
    }
};
