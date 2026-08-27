// Question Link: https://leetcode.com/problems/two-sum/description/

// METHOD 1: Brute Force 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int n = nums.size();
       for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; 
    }
};

// METHOD 2: Optimized --> Used hashmap 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mpp;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int a = nums[i];
            int more = target - a;
            if(mpp.find(more) != mpp.end()){
                v.push_back(mpp[more]);
                v.push_back(i);
                return v;
            }
            mpp[a] = i;
        }
        return v;
    }
};


