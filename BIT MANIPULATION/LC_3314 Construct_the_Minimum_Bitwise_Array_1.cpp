// Question Link: https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/


// METHOD 1: BRUTE FORCE ----> iterating through all the elements for n number of times ---  n is the size of each number

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(auto &e : nums){
            bool fnd = false;
            for(int i = 1; i <= e; i++){
                if(int(i | (i+1)) == e){
                    ans.push_back(i);
                    fnd = true;
                    break;
                }
            }
            if(fnd == false){
                ans.push_back(-1);
            }

        }

        return ans;
    }
};
