// Question Link: https://leetcode.com/problems/find-peak-element/description/

// METHOD 1: 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

      // Tackle edge cases first 
        if(n == 1){
            return 0;
        }
        if(nums[0] > nums[1]){
            return 0;
        }
        if(nums[n - 1] > nums[n - 2]){
            return n - 1;
        }
      // shrinked the required array
        int low = 1;
        int high = n - 2;

        while(low <= high){
            int mid = low + (high - low)/2;

          // If mid is peak then return 
            if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]){
                return mid;
            }
              // if mid lies on increasing slope means peak is at right 
            else if(nums[mid] > nums[mid - 1]){
                low = mid + 1;
            }
              // other wise peak is at left
            else{
                high = mid - 1;
            }
        }

        return 0;
    }
};
