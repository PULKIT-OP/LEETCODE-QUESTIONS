// Question Link: https://leetcode.com/problems/largest-perimeter-triangle/description/

// METHOD 1: 

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        for(int i = n-1; i >= 0 && i-2 >= 0; i--){
            if((nums[i-2] + nums[i-1]) > nums[i]){
                ans = max(ans, (nums[i-2] + nums[i-1] + nums[i]));
            }
        }

        return ans;
    }
};

// METHOD 2: Realized, that after sorting we dont have to check if the perimeter we getting is largest or not --> its gonna be largest as we are traversing from last

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = n-1; i >= 0 && i-2 >= 0; i--){
            if((nums[i-2] + nums[i-1]) > nums[i]){
                return (nums[i-2] + nums[i-1] + nums[i]);
            }
        }

        return 0;
    }
};
