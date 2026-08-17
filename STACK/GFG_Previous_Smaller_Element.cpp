// Question Link: https://www.geeksforgeeks.org/problems/previous-smaller-element/1

// METHOD 1: 

class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        stack<int> st;
        
        vector<int> result(n, -1);
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                result[i] = st.top();
                st.push(arr[i]);
            }
            else{
                st.push(arr[i]);
            }
        }
        
        return result;
    }
};
