// Question Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

// METHOD 1: binary search template simple question

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        int ans = INT_MAX;
        while(s <= e){
            int mid = s + (e - s)/2;
            // Left half sorted??
            if(nums[mid] >= nums[s]){
                ans = min(ans, nums[s]);  // take minimum of left half
                s = mid + 1;
            }
            else{
                // Right half sorted??    
                ans = min(ans, nums[mid]);    // take minimum of right half
                e = mid - 1;
            }
        }

        return ans;
    }
};
