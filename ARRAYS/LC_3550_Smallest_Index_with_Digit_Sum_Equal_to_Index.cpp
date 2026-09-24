// Question Link: https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/description/

// METHOD 1:

class Solution {
public:
    int countDigitSum(int n){

        int result = 0;
        while(n > 0){
            result += (n%10);
            n = n/10;
        }

        return result;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        int result = INT_MIN;
        for(int i = 0; i < n; i++){
            int sum = countDigitSum(nums[i]);
            if(sum == i){
                return i;
            }
        }

        return -1;
    }
};
