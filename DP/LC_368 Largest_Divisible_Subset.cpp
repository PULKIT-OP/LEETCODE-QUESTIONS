// Question Link: https://leetcode.com/problems/largest-divisible-subset/

// METHOD 1: Using Recursion ---> TLE AAEGA LAADLE

class Solution {
public:
    vector<int> solve(int i, int last, vector<int> &nums){
        if(i >= nums.size()){
            return {};
        }

        vector<int> take;
        if(last == -1 || nums[i]%nums[last] == 0){
            take.push_back(nums[i]);
            vector<int> next = solve(i+1, i, nums);
            take.insert(take.end(), next.begin(), next.end());
        }
        vector<int> skip = solve(i+1, last, nums);

        if(take.size() > skip.size()){
            return take;
        }

        return skip;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        return solve(0, -1, nums);
    }
};


// METHOD 2: BOTTOM UP 

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> parent(n, -1);

        vector<int> dp(n, 1);
        int maxi = 1;
        int max_idx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i]%nums[j] == 0){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                    if(dp[i] > maxi){
                        maxi = dp[i];
                        max_idx = i;
                    }
                }
            }
        }
        int i = max_idx;
        vector<int> result;
        while(parent[i] != -1){
            result.push_back(nums[i]);
            i = parent[i];
        }
        result.push_back(nums[i]);
        reverse(result.begin(), result.end());
        return result;
    }
};
