// Question Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/description


// METHOD 1: Normal method nothing much

class Solution {
public:
    int n;
    int minMoves(vector<int>& nums) {
        n = nums.size();
        int maxVal = nums[n-1];
        for(int i = 0; i < n; i++){
            maxVal = max(maxVal, nums[i]);
        }

        int count = 0;
        for(int i = 0; i < n/2; i++){
            count += (maxVal - nums[i]);
            count += (maxVal - nums[n-i-1]);
        }

        if(n%2 == 1){
            count += (maxVal - nums[n/2]);
        }

        return count;
    }
};
