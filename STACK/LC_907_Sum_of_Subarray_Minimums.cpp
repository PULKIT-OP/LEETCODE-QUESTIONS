// Question Link: https://leetcode.com/problems/sum-of-subarray-minimums/description/

// METHOD 1: BRUTE FORCE ---> TLE

class Solution {
public:
    int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int mini = arr[i];
            for(int j = i; j < n; j++){
                mini = min(mini, arr[j]);
                ans = (ans + mini)%MOD;
            }
        }

        return ans;
    }
};


// METHOD 2: Optimized method using Previous Smaller element and Next smaller element algorithms

class Solution {
public:
    int MOD = 1e9 + 7;
    int n;
    void nextSmallerElement(vector<int> &arr, vector<int> &result){
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                result[i] = st.top();
                st.push(i);
            }
            else{
                st.push(i);
            }
        }
    }
    
    void previousSmallerElement(vector<int> &arr, vector<int> &result){
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()){
                result[i] = st.top();
                st.push(i);
            }
            else{
                st.push(i);
            }
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        n = arr.size();
        vector<int> PSE(n, -1);    // stores idx
        vector<int> NSE(n, n);    // stores idx (virtual boundary)

        previousSmallerElement(arr, PSE);
        nextSmallerElement(arr, NSE);
        int total = 0;

        for(int i = 0; i < n; i++){
            int left = i - PSE[i];
            int right = NSE[i] - i;

            total = (total + (left*right*(long long)arr[i]))%MOD;
        }

        return total;
    }
};
