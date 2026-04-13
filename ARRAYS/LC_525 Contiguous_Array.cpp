// Question Link: https://leetcode.com/problems/contiguous-array/description/


// METHOD 1: Using cumulative sum logic

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;  // storing maximum length of subarray
        int sum = 0; // storing cumulative sum
        unordered_map<int, int> mp; // storing cumulative sum with index
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            sum += (nums[i] == 0 ? -1 : 1);
            if(mp.find(sum) != mp.end()){
                maxi = max(maxi, i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }

        return maxi;
    }
};
