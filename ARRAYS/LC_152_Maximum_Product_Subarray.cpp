// Question Link: https://leetcode.com/problems/maximum-product-subarray/description/


// METHOD 1: 

class Solution {
public:
    int n;
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int pre = 1;
        int suff = 1;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            if(pre == 0){
                pre = 1;
            }
            if(suff == 0){
                suff = 1;
            }

            pre = pre * nums[i];
            suff = suff * nums[n-i-1];

            maxi = max(maxi, max(pre, suff));
        }

        return maxi;
    }
};
