// Question Link: https://leetcode.com/problems/construct-uniform-parity-array-i/description/

// METHOD 1:
/*

There can be three cases only: 
  1. All elements of nums1 are even. If this is the case then just copy paste the same number in nums2 with rule 1 and return true, as now we have complete even array
  2. All elements of nums1 are odd. If this is the case then just copy paste the same number in nums2 with rule 1 and return true, as now we have complete odd array
  3. If both even and odd elements are mixed up, it means we have atleast 1 even and atleast 1 odd. Then we can make new array of all odd numbers, just copy pase the odd numbers in new array on same index,
  and at the place of even nubmer put the diff bw odd and even nubmer that we have already. now we have new array of complete odd numbers

  So At last in all the cases we can make this type of array with the given two rules.

*/
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};
