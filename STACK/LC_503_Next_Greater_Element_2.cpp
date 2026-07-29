// Question Link: https://leetcode.com/problems/next-greater-element-ii/description/


// METHOD 1: Brute Force method --> for each element you iterate from that element to last element and then from first element to that element the next greater element you find is your answer for that index


// METHOD 2: O(n^2)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);

        for(int i = 0; i < n; i++){
            for(int j = i+1; j <= i+n-1; j++){
                int idx = j%n;
                if(nums[idx] > nums[i]){
                    result[i] = nums[idx];
                    break;
                }
            }
        }

        return result;
    }
};

// METHOD 3: OPTIMIZED but long


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;

        for(int i = 2*n-1; i >= 0; i--){
            if(i < n){
                if(!st.empty()){
                    if(st.top() > nums[i%n]){
                        result[i%n] = st.top();
                        st.push(nums[i%n]);
                    }
                    else{
                        while(!st.empty() && st.top() <= nums[i%n]){
                            st.pop();
                        }
                        if(!st.empty()){
                            result[i%n] = st.top();
                            st.push(nums[i%n]);
                        }
                        else{
                            st.push(nums[i%n]);
                            result[i%n] = -1;
                        }
                    }
                }
                else{
                    result[i%n] = -1;
                    st.push(nums[i%n]);
                }
            }
            else{
                if(!st.empty()){
                    if(st.top() > nums[i%n]){
                        st.push(nums[i%n]);
                    }
                    else{
                        while(!st.empty() && st.top() <= nums[i%n]){
                            st.pop();
                        }
                        if(!st.empty()){
                            st.push(nums[i%n]);
                        }
                        else{
                            st.push(nums[i%n]);
                        }
                    }
                }
                else{
                    st.push(nums[i%n]);
                }
            }
        }

        return result;
    }
};


// METHOD 4: OPTIMIZED as above (same logic) but small version

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;

        for(int i = 2*n-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            if(i < n && !st.empty()){
                if(st.top() > nums[i%n]){
                    result[i%n] = st.top();
                    st.push(nums[i%n]);
                }
            }
            else{
                st.push(nums[i%n]);
            }
        }

        return result;
    }
};
