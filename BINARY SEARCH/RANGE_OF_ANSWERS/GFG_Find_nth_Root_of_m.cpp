// Question Link: https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1


// METHOD 1: Binary Search just like square root of n

class Solution {
  public:
    int multi(int num, int power){
        int ans = num;
        for(int i = 1; i < power; i++){
            ans = ans*num;
        }
        
        return ans;
    }
    int nthRoot(int n, int m) {
        // Code here
        int low = 1;
        int high = m;
        
        if(m == 0 || m == 1){
            return m;
        }
        
        while(low <= high){
            int mid = low + (high - low)/2;
            int val = multi(mid, n);
            
            if(val == m){
                return mid;
            }
            else if(val < m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return -1;
    }
};
