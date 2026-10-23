// Question Link: https://leetcode.com/problems/maximum-k-to-sort-a-permutation/description


// METHOD 1: Using Observation 
// here we assumed k is maximum possible number
// we only need numbers which are not at their actual position. And we have to swap those numbers among themselves to get a sorted arry
// but the main trick is we can only swap two numbers if they have exact same set bit as of k, they can carry extra set bit but the minimum requirement is that
// we doing this because we need maximum possible k so try to set as many bits as possible
// Now just take & of k and misplaced numbers to get maximum possible k
class Solution {
public:
    int n;
    int sortPermutation(vector<int>& nums) {
        n = nums.size();
        int k = -1;   // all bits set in -1
        for(int i = 0; i < n; i++){
            if(nums[i] != i){
                k = (k & nums[i]);
            }
        }

        return k == -1 ? 0 : k;
    }
};
