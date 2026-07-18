// Question Link: https://leetcode.com/problems/single-number/description/


// METHOD 1: Using XOR opertor
// Because XOR of two same number is ZERO, and XOR of zero and a integer is that integer itself.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int XOR = 0;
        for(int i = 0; i < n; i++){
            XOR = XOR ^ nums[i];
        }

        return XOR;
    }
};
