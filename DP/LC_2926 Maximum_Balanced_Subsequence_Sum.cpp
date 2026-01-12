// Question Link: 

// METHOD 1: RECURSION ----> TLE aaega LAADLE

class Solution {
public:
    long long solve(vector<int> &nums, int i, int prev){
        if(i >= nums.size()){
            return 0;
        }

        long long take = INT_MIN;
        long long skip = INT_MIN;

        if(prev == -1 || nums[i] - i >= nums[prev] - prev){
            take = nums[i] + solve(nums, i+1, i);
        }
        skip = solve(nums, i+1, prev);

        return max<long long>(take, skip);
    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();

        long long maxEle = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxEle){
                maxEle = nums[i];
            }
        }
        if(maxEle <= 0){
            return maxEle;
        }

        return solve(nums, 0, -1);
    }
};




// METHOD 2: MEMOIZATION ---> USING UNORDERED_MAP cuz 10^5 size of array not possible   ---->  TLE aaega LAADLE memo me bhi  --->  316/345
class Solution {
public:
    unordered_map<string, int> dp;
    long long solve(vector<int> &nums, int i, int prev){
        if(i >= nums.size()){
            return 0;
        }

        string key = to_string(prev) + "_" + to_string(i);

        if(dp.find(key) != dp.end()){
            return dp[key];
        }

        long long take = INT_MIN;
        long long skip = INT_MIN;

        if(prev == -1 || nums[i] - i >= nums[prev] - prev){
            take = nums[i] + solve(nums, i+1, i);
        }
        skip = solve(nums, i+1, prev);

        return dp[key] = max<long long>(take, skip);
    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();

        long long maxEle = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxEle){
                maxEle = nums[i];
            }
        }
        if(maxEle <= 0){
            return maxEle;
        }

        return solve(nums, 0, -1);
    }
};


// METHOD 3: MORE OPTIMIZATION ---> BOTTOM UP   ---->  BETE Yaha bhi TLE aaega   --->  341/345   ----> SYSTUMMM HANG BHAI 

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();

        long long maxEle = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxEle){
                maxEle = nums[i];
            }
        }
        if(maxEle <= 0){
            return maxEle;
        }

        vector<long long> dp(n);
        for(int i = 0; i < n; i++){
            dp[i] = nums[i];
        }

        long long maxSum = INT_MIN;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] - i >= nums[j] - j){
                    dp[i] = max<long long>(dp[i], dp[j] + nums[i]);
                    maxSum = max(dp[i], maxSum);
                }
            }
        }

        return maxSum > maxEle ? maxSum : maxEle;
    }
};

// METHOD 4: EVEN MORE OPTIMIZATION

