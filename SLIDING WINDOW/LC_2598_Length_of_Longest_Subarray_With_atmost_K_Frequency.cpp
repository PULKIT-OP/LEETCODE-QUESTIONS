// Question Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description

// METHOD 1: Using Sliding Window

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1 && k == 1){
            return 1;
        }
        else if(n == 1 && k != 1){
            return 0;
        }
        unordered_map<int, int> mp; // to store frequency of elements
        int ans = 0;
        int i = 0; 
        int j = 0;

        while(i <= j && j < n){
            mp[nums[j]]++;  // increment frequency 

          // Now decrease freqency of 'j' until it gets below k
            while(mp[nums[j]] > k){
                mp[nums[i]]--;
                i++;
            }
          // and store the maximum size
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};
