// Question Link: https://leetcode.com/problems/sum-of-subarray-ranges/description/

// METHOD 1: BruteForce Method ---> Just iteration

class Solution {
public:
    int n;
    long long subArrayRanges(vector<int>& nums) {
        n = nums.size();

        long long sum = 0;
        for(int i = 0; i < n; i++){
            int mini = nums[i];
            int maxi = nums[i];
            for(int j = i+1; j < n; j++){
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                sum += (maxi - mini);
            }
        }

        return sum;
    }
};


// METHOD 2: Using Stacksn ---> Previous-Next Smaller-Greater element

class Solution {
public:
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

    void previousGreaterElement(vector<int> &arr, vector<int> &result){
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
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

    void nextGreaterElement(vector<int> &arr, vector<int> &result){
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
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

    long long sumSubarrayMin(vector<int> &arr){
        n = arr.size();
        vector<int> PSE(n, -1);    // stores idx
        vector<int> NSE(n, n);    // stores idx

        previousSmallerElement(arr, PSE);
        nextSmallerElement(arr, NSE);
        long long total = 0;

        for(int i = 0; i < n; i++){
            int left = i - PSE[i];
            int right = NSE[i] - i;

            total = (total + (left*right*(long long)arr[i]));
        }

        return total;
    }

    long long sumSubarrayMax(vector<int> &arr) {
        n = arr.size();
        vector<int> PGE(n, -1);
        vector<int> NGE(n, n);
        
        previousGreaterElement(arr, PGE);
        nextGreaterElement(arr, NGE);
        long long total = 0;
        
        for(int i = 0; i < n; i++){
            int left = i - PGE[i];
            int right = NGE[i] - i;
            
            total += (left*right*(long long)arr[i]);
        }
        
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        n = nums.size();

        return (long long)sumSubarrayMax(nums) - (long long)sumSubarrayMin(nums);
    }
};
