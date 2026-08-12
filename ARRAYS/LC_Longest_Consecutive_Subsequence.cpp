// Question Link: https://leetcode.com/problems/longest-consecutive-sequence/description

// METHOD 1:  Continuously calculate longest subsequence after sorting, the moment you see any element that cant be part of consecutive subsequence that moment you save the maximum subsequence you found till now
// then start freshh from 1 and then calculate again from there by the end of array you will have final ans then just return it

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());

        int longest = 1;
        int prev = nums[0];
        int ans = 1;

        for(int i = 1; i < n; i++){
            if(prev == nums[i]){
                continue;
            }
            else if(prev == INT_MIN){
                prev = nums[i];
                longest++;
            }
            else if(prev == nums[i]-1){
                prev = nums[i];
                longest++;
            }
            else{
                ans = max(ans, longest);
                prev = nums[i];
                longest = 1;
            }
        }

        ans = max(ans, longest);

        return ans;
    }
};
