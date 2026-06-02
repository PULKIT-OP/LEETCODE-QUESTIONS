// Question Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// METHOD 1: Binary Search: Lower Bound + Upper Bound mix

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        int start = -1;
        int end = -1;
        // Starting position
        while(s <= e){
            int mid = s + (e - s)/2;
            if(nums[mid] == target){
                start = mid;
                e = mid -1;  // may be there exist a smaller index of this number so just trying to checkout that bitch.
            }
            else if(nums[mid] > target){
                e = mid - 1;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
        }

        // Ending Position
        s = 0;
        e = nums.size() - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(nums[mid] == target){
                end = mid;
                s = mid + 1;  // may be there exist a greater index of that nubmer x, so just trying to check that bitch out.
            }
            else if(nums[mid] > target){
                e = mid - 1;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
        }
      
        return {start, end};
    }
};
