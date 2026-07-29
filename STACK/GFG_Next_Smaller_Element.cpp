// Question Link: https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1

// METHOD 1: Monotonic stack logic

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> st;
        
        for(int i = n-1; i >= 0; i--){
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
