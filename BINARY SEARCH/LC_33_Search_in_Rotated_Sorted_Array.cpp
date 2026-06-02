// Question Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

// METHOD 1: 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        // checking which half is sorted and of my concern in finding target
        while(s <= e){
            int mid = s + (e - s)/2;
            if(target == nums[mid]){
                return mid;
            }

          // left half sorted???
            if(nums[s] <= nums[mid]){
                if(target <= nums[mid] && target >= nums[s]){
                    e = mid - 1;    // forget the right half we got the valuable part of array
                }
                else{
                    s = mid + 1;    // forget the left half we got the valuable part of array
                }
            }
          // Right half sorted??
            else{
                if(target > nums[mid] && target <= nums[e]){
                    s = mid + 1;    // forget the left half we got the valuable part of array
                }
                else{
                    e = mid - 1;    // forget the right half we got the valuable part of array
                }
            }
        }

        return -1;
    }
};
