// Question Link: https://leetcode.com/problems/contains-duplicate-ii/description/


// METHOD 1: Brute Force Method --> TLE

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = i+1; abs(j - i) <= k && j < n; j++){
                if(nums[i] == nums[j]){
                    return true;
                }
            }
        }

        return false;
    }
};

// METHOD 2: Optimized Method --> Using HashMaps

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) != mp.end()){
                if(i - mp[nums[i]] <= k){
                    return true;
                }
            }
            mp[nums[i]] = i;
        }

        return false;
    }
};


