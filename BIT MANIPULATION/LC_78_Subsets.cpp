// Question Link: https://leetcode.com/problems/subsets/description/

// METHOD 1: Using BIT MANIPULATION
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n;
        vector<vector<int>> result;
        for(int i = 0; i < subsets-1; i++){
            vector<int> temp;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    temp.push_back(nums[j]);
                }
            }
            result.push_back(temp);
        }
        result.push_back(nums);
        return result;
    }
};
