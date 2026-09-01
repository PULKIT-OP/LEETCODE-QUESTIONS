// Question Link: https://leetcode.com/problems/maximum-sum-circular-subarray/


// METHOD 1: Using Kadane's Algo ---> With a little tweak
// If we somehow find the minimum subarray sum of the given array, then total_sum - mini_sum will be our max sub array sum
// so we are doing the same here.
// but we are also finding the maximum subarray sum for the noraml array not circular one --> so that if we find it that will be our ans otherwise return the ans as per method

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int maxSum = nums[0];  // storing maximum Subarray sum 
        int minSum = nums[0];  // storing minimum subarray sum
        int total_sum = nums[0];  // storing total sum

        int currMin = nums[0];  // min sum till curr idx
        int currMax = nums[0];  // max sum till curr idx

        for(int i = 1; i < n; i++){
            currMax = max(currMax+nums[i], nums[i]);
            maxSum = max(currMax, maxSum);

            currMin = min(currMin+nums[i], nums[i]);
            minSum = min(currMin, minSum);

            total_sum += nums[i];
        }

      // if we find maxsum as negative then this is the answer
        if(maxSum < 0){
            return maxSum;
        }

        return max(maxSum, total_sum - minSum);
    }
};
