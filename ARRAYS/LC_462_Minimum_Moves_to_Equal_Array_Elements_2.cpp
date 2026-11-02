// Question Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii


// METHOD 1: Normal Method 

class Solution {
public:
    int n;
    int minMoves2(vector<int>& nums) {
        n = nums.size();

        sort(nums.begin(), nums.end());
        int midEle = nums[n/2];
        int count = 0;
        for(int i = 0; i < n; i++){
            count += abs(nums[i] - midEle);
        }

        return count;
    }
};


// METHOD 2: Modified For loop for reduced operations

class Solution {
public:
    int n;
    int minMoves2(vector<int>& nums) {
        n = nums.size();

        sort(nums.begin(), nums.end());
        int midEle = nums[n/2];
        int count = 0;
        for(int i = 0; i < n/2; i++){
            count += abs(nums[i] - midEle);
            count += abs(nums[n-i-1] - midEle);
        }

        return count;
    }
};


// METHOD 3: Using STL for nth sorted element

class Solution {
public:
    int n;
    int minMoves2(vector<int>& nums) {
        n = nums.size();

        nth_element(nums.begin(), nums.begin() + n/2, nums.end());
        int midEle = nums[n/2];
        int count = 0;
        for(int i = 0; i < n/2; i++){
            count += abs(nums[i] - midEle);
            count += abs(nums[n-i-1] - midEle);
        }

        return count;
    }
};
