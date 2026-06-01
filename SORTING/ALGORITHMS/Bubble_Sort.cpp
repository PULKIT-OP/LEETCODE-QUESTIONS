// Question Link: https://www.geeksforgeeks.org/problems/bubble-sort/1

// Method 1: Find BB(Biggest Bubble) and push it to last
class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-i; j++){
                if(arr[j] > arr[j+1] && j+1 < n-i){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
};
