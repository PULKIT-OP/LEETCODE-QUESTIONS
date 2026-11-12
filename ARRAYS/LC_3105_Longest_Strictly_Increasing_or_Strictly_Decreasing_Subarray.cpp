// Question Link: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description


// METHOD 1: Normal Observation and direct question

class Solution {
public:
    int n;
    int longestMonotonicSubarray(vector<int>& nums) {
        n = nums.size();

        int result = 0;
        int inc = 1;
        int dec = 1;
        int j = 1;

        while(j < n){
            if(nums[j] > nums[j-1]){
                result = max(result, dec);
                dec = 1;
                inc++;
            }
            else if(nums[j] < nums[j-1]){
                result = max(result, inc);
                inc = 1;
                dec++;
            }
            else if(nums[j] == nums[j-1]){
                result = max({result, inc, dec});
                inc = 1;
                dec = 1;
            }
            j++;
        }

        result = max({result, inc, dec});
        return result;
    }
};
