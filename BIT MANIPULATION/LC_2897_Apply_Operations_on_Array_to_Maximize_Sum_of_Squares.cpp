// Question Link: https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/description/


// METHOD 1: Using Bit Manipulation

// Total sum of the array is fixed Just using this property
// Whenever you perform the operation with any two numbers ---> Total sum after the operation is as same as before


class Solution {
public:
    int n;
    int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        n = nums.size();

        vector<int> count(32, 0);

        for(int e : nums){
            for(int i = 0; i < 32; i++){
                int curr = (1 << i);
                if((e & curr) == curr){
                    count[i]++;
                }
            }
        }

        int result = 0;
        while(k--){
            int curr = 0;

            for(int b = 0; b < 32; b++){
                if(count[b] > 0){
                    curr = (curr | (1 << b));
                    count[b]--;
                }
            }
            result = (result + 1LL*curr*curr)%MOD;
        }

        return result;
    }
};
