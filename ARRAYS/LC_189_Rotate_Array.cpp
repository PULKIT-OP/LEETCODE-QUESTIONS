// Question Link: https://leetcode.com/problems/rotate-array/description/

// METHOD 1: Optimized version

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n == 1){
            return;
        }

        k = k%n;

        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin()+k);

        reverse(nums.begin()+k, nums.end());

    }
};
