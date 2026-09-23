// Question Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/

// METHOD 1:

class Solution {
public:
    int n;
    int minOperations(vector<int>& nums, int x) {
        n = nums.size();

        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            mp[sum] = i;
        }

        if(sum < x){
            return -1;
        }

        int remaining_sum = sum - x;
        int longestSubArray = INT_MIN;

        sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int findSum = sum - remaining_sum;

            if(mp.find(findSum) != mp.end()){
                int idx = mp[findSum];
                longestSubArray = max(longestSubArray, i - idx);
            }
        }

        return longestSubArray == INT_MIN ? -1 : n - longestSubArray;
    }
};
