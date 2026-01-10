// https://leetcode.com/problems/house-robber-ii/description/

// MAIN logic behing solving this question is, if you took first house then you cant take last house and and and if you skipped first house then you can take last house
// so we will take two cases in starting 1. take first house ----> Call house robber 1 from 0th house to last second house 
//                                       2. skip first house ----> Call house robber 1 from 1st house to last house 


// METHOD 1: RECURSION ---> TLE dega LAADLE

class Solution {
public:
// house robber 1 code
    int solve(vector<int> &nums, int i, int n){
        if(i > n){
            return 0;
        }
        int take = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        return max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

      // tacking and edge case if there is only one house then you have to steal it to maximize your profit
        if(n == 1){
            return nums[0];
        }

      // Calling solve function for 0 to n-2 means we are stealing first house 
        int take_0 = solve(nums, 0, n-2);
      // Calling solve funciton for 1 to n-1 means we are skipping first house
        int skip_0 = solve(nums, 1, n-1);

      // takig maximum of above two
        return max(take_0, skip_0);
    }
};


// METHOD 2: MEMOIZATION ---> STORING REPEATING ANSWERS

class Solution {
public:

// House Robber 1 memoization logic same to same
    int dp[101];
    int solve(vector<int> &nums, int i, int n){
        if(i > n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        int take = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        return dp[i] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }
        
        memset(dp, -1, sizeof(dp));
        int take_0 = solve(nums, 0, n-2);

      // memset is again bocz we are solving two different problems here separatly
        memset(dp, -1, sizeof(dp));
        int skip_0 = solve(nums, 1, n-1);

        return max(take_0, skip_0);
    }
};

// METHOD 3: BOTTOM UP 

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        vector<int> dp(101);

      // CASE 1: Skipping first house means ---> money from house 1 is zero
        dp[0] = 0;
        dp[1] = 0;

      // if you skipped 1st house then you will start from 2nd house and go till last(nth) house
        for(int i = 2; i <= n; i++){
            int take = nums[i-1] + (i-2 > 0 ? dp[i-2] : 0);
            int skip = dp[i-1];

            dp[i] = max(take, skip);
        }

      // Storing maximum money we can steal if we skipped first house which will be stored in dp[n] as the last house we visited was nth
        int skip_1 = dp[n];

      // Now clear the dp array for our next iteration
      // Now we will not skip first house so we have not marked first house as zero
        dp.clear();
        dp[0] = 0;

      // As we are not skipping first house so, we will start from first house and go till n-1th house (last second house)
        for(int i = 1; i <= n-1; i++){
            int take = nums[i-1] + (i-2 > 0 ? dp[i-2] : 0);
            int skip = dp[i-1];

            dp[i] = max(take, skip);
        }

      // Now storing maximum money we can have which is stored in dp[n-1] as we visited n-1th house at last
        int take_1 = dp[n-1];

      // Now return maximum of the two answers
        return max(take_1, skip_1);
    }
};


// METHOD 4: CONSTANT SPACE
// Here the main logic remains the same as bottom up, we are just optimizing space 
// just look at the bottom up code, you will see in both the cases we have two variables take and skip, in those varialbes you wil see two more variables as dp[i-1] and dp[i-2].
// If you look at these vairables and observe it carefully, its nothing but prev total vaule and prev of prev total values, with respect to your current node.
// We just need to store these values in a variable and we dont need any array to store these 

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // handling corner case if we have only one house in array
        if(n == 1){
            return nums[0];
        }

    // CASE 1: If we SKIP first house
        // storing prev_prev and prev value
        // 
        int prev_prev = 0;
        int prev = 0;
        int result_1 = 0;
        // skipped first house menas we will start with second house
        for(int i = 2; i <= n; i++){
            
            int take = nums[i-1] + prev_prev;
            int skip = prev;
            // storing final ans in result
            result_1 = max(take, skip);
            // updating prev_prev and prev
            prev_prev = prev;
            prev = result_1;
        }

    // CASE 2: If we TAKE first house
        // resetting variables for next case
        prev = 0;
        prev_prev = 0;
        int result_2 = 0;

        // if we are taking first house so we will start from first house
        for(int i = 1; i <= n-1; i++){
            int take = nums[i-1] + prev_prev;
            int skip = prev;

            // storing fianl answer and updating variables
            result_2 = max(take, skip);
            prev_prev = prev;
            prev = result_2;
        }

        // return maximum of both the final answers
        return max(result_1, result_2);
    }
};
