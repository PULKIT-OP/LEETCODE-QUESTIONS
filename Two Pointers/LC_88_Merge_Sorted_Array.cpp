// Question Link: https://leetcode.com/problems/merge-sorted-array/description/


// METHOD 1: Normal brute force method

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> test;
        for(int i = 0; i < m; i++){
            test.push_back(nums1[i]);
        }

        int i = 0;
        int j = 0;
        int idx = 0;
        while(i < m && j < n){
            if(nums2[j] < test[i]){
                nums1[idx] = nums2[j];
                j++;
            }
            else{
                nums1[idx] = test[i];
                i++;
            }
            idx++;
        }

        while(i < m){
            nums1[idx] = test[i];
            i++;
            idx++;
        }
        while(j < n){
            nums1[idx] = nums2[j];
            j++;
            idx++;
        }
    }
};

// METHOD 2: Filling answer from last ---> to decrease extra iteration and space 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        while(j >= 0){
            nums1[k] = nums2[j];
            k--;
            j--; 
        }

    }
};
