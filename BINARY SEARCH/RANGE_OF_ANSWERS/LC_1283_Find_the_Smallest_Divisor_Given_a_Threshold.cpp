// Question Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

// METHOD 1: Koko eating banana kinda problem ---> same code works on both the problem 

class Solution {
public:
    int findSum(int div, vector<int> &nums, int size){
        int sum = 0;
        for(int i = 0; i < size; i++){
            // sum = sum + ceil((double)nums[i]/div); // ----> builtIn function for ceil value
            sum = sum + (nums[i] + div - 1)/div;  // ----> Formula for ceil value
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low + (high - low)/2;

            int sum = findSum(mid, nums, n);
            if(sum <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};
