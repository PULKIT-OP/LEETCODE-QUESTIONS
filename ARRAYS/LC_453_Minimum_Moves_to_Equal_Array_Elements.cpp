// Question Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description


// METHOD 1: Brute Force

class Solution {
public:
    int n;
    int maxi(vector<int> &nums){
        int maxIdx = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[maxIdx]){
                maxIdx = i;
            }
        }

        return maxIdx;
    }
    bool all_element_equal(vector<int> &nums){
        for(int i = 0; i < n-1; i++){
            if(nums[i] != nums[i+1]){
                return false;
            }
        }

        return true;
    }
    int minMoves(vector<int>& nums) {
        n = nums.size();
        
        int count = 0;
        while(!all_element_equal(nums)){
            int maxIdx = maxi(nums);
            for(int i = 0; i < n; i++){
                if(i == maxIdx){
                    continue;
                }
                nums[i]++;
            }
            count++;
        }

        return count;
    }
};


// METHOD 2: Observation:

class Solution {
public:
    int n;
    int minMoves(vector<int>& nums) {
        n = nums.size();
        
        int count = 0;
        int minVal = *min_element(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            count += (nums[i] - minVal);
        }

        return count;
    }
};
