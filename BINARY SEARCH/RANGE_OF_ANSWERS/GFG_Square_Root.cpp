// Question Link: https://www.geeksforgeeks.org/problems/square-root/1

// METHOD 1: Use direct builtin function ----> GAY Types method

// METHOD 2: Binary Search:

class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int low = 0; 
        int high = n;
        
        while(low <= high){
            long long mid = low + (high - low)/2;
            long long val = mid * mid;
            
            if(val <= n){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return high;
    }
};
