// Question Link: https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1


// METHOD 1: Binary Search ---> Just like Upper Bound ---> If done that then its a shit question

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int s = 0;
        int e = arr.size() - 1;
        int ans = -1;
        
        while(s <= e){
            int mid = s + (e - s)/2;
            
            if(arr[mid] == x){
                ans = mid;
                e = mid - 1;
            }
            else if(arr[mid] < x){
                s = mid + 1;
            }
            else if(arr[mid] > x){
                ans = mid;
                e = mid - 1;
            }
        }
        
        return ans;
    }
};
