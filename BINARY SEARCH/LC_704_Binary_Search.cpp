// Question Link: 

// METHOD 1: Using Binary Search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int result = -1;

        int s = 0; 
        int e = nums.size() - 1;
        
        while(s <= e){
            int mid = s + (e - s)/2;    // Standard and SAFE formula for mid ---> it prevents the overflow of integer when the numbers are large
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                e = mid - 1;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
        }

        return result;
    }
};
