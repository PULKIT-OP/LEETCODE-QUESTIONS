// Question Link: https://www.geeksforgeeks.org/problems/implement-upper-bound/1

// METHOD 1: Binary Search With a LITTLE TWEAK

class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int s = 0;
        int e = arr.size() - 1;
        
        int idx = INT_MAX;
        
        while(s <= e){
            int mid = s + (e - s)/2;
            
            if(arr[mid] == target){
                s = mid + 1;    // -----> The TWEAK it needs
            }
            else if(arr[mid] > target){
                if(mid < idx){
                    idx = mid;
                }
                e = mid - 1;
            }
            else if(arr[mid] < target){
                s = mid + 1;
            }
        }
        if(idx == INT_MAX){
            return arr.size();
        }
        return idx;
    }
};
