// Question Link: https://leetcode.com/problems/subarray-sum-equals-k/


// METHOD 1: Brute Force

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum == k){
                    result++;
                }
            }
        }

        return result;
    }
};


// METHOD 2: Using cumulative sum logic

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;

        unordered_map<int, int> mp;
        mp[0]++;

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(mp.find(sum-k) != mp.end()){
                result += mp[sum-k];
            }
            mp[sum]++;
        }

        return result;
    }
};
