// Question Link: https://leetcode.com/problems/find-peak-element/description/


// METHOD 1: USING BINARY SEARCH  --->  IF O(logn) complexity constraint, otherwise you can use linear search as well

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        if(nums[0] > nums[1]){
            return 0;
        }
        if(nums[n-1] > nums[n-2]){
            return n-1;
        }

        int l = 1;
        int r = n-2;

        int ans = -1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                ans = mid;
                break;
            }
            else if(nums[mid] < nums[mid+1]){
                l = mid+1;
            }
            else if(nums[mid] < nums[mid-1]){
                r = mid-1;
            }
        }

        return ans;
    }
};
