// Question Link: https://www.geeksforgeeks.org/problems/insertion-sort/1

// Method 1: Put each element at its correct position, iteratively. Lenght of workspace increases at each iteration
// TC: O(N^2)
class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int j = i;
            for(int k = j; k >= 0; k--){
                if(arr[k] < arr[k-1] && k-1 >= 0){
                    swap(arr[k], arr[k-1]);
                }
            }
        }
    }
};
