// Question Link: https://leetcode.com/problems/maximize-sum-after-at-most-k-digit-rearrangements/


// METHOD 1: BruteForce Kinda Solution

class Solution {
public:
    int n;
    int rearrangeDigits(int d){
        int temp = d;
        vector<int> digits;
        while(temp > 0){
            digits.push_back(temp%10);
            temp = temp/10;
        }

        sort(digits.begin(), digits.end());

        temp = 0;
        while(!digits.empty()){
            int dig = digits.back();
            temp = (temp * 10) + dig;
            digits.pop_back();
        }

        return temp;
    }
    long long maximizeSum(vector<int>& nums, int k) {
        n = nums.size();

        vector<int> gains(n, 0);
        long long originalSum = 0;
        for(int i = 0; i < n; i++){
            originalSum += nums[i];
            int g = rearrangeDigits(nums[i]) - nums[i];
            gains[i] = g;
        }

        sort(gains.begin(), gains.end());

        while(k--){
            originalSum += gains.back();
            gains.pop_back();
        }

        return originalSum;
    }
};
