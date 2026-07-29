// Question Link: https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1

// METHOD 1: 

class Solution {
  public:
    vector<int> countGreater(vector<int> &arr, vector<int> &indices) {
        // code here
        int n1 = arr.size();
        int n2 = indices.size();
        
        vector<int> result(n2, 0);
        
        for(int i = 0; i < n2; i++){
            int idx = indices[i];
            for(int j = indices[i]+1; j < n1; j++){
                if(arr[j] > arr[idx]){
                    result[i]++;
                }
            }
        }
        
        return result;
    }
};
