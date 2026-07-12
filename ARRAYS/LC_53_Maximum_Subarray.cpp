// Question Link: https://leetcode.com/problems/maximum-subarray/description/

// METHOD 1: 
// There are only two things we are doing, either start a new array sum or continue with the previous one

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MIN;
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum = sum + nums[i];   // continuing with the previous one for now
            result = max(sum, result);  // store the maximum sum as of now
            if(sum < 0){
                sum = 0; // startig a new sum now
            }
        }

        return result;  // at last return result
    }
};
