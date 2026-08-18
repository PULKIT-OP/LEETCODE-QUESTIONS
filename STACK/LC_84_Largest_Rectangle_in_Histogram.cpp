// Question Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/


// METHOD 1: Using Stack --> Previous Smaller and Next Smaller element method ---> It acts as brute force method but will work eventually

class Solution {
public:
    int n;
    void previousSmallerElement(vector<int> &arr, vector<int> &result){
        stack<int> st;
        for(int i = 0; i < n; i++){
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
    void nextSmallerElement(vector<int> &arr, vector<int> &result){
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
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


    int largestRectangleArea(vector<int>& heights) {
        n = heights.size();
        if(n == 1){
            return heights[0];
        }
        vector<int> PSE(n, -1);
        vector<int> NSE(n, n);

        previousSmallerElement(heights, PSE);
        nextSmallerElement(heights, NSE);

        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int width = NSE[i] - PSE[i] - 1;
            maxArea = max(maxArea, width*heights[i]);
        }

        return maxArea;

    }
};


// METHOD 2: Using Stack ---> But with only one pass solution ---> Takes less time than previous one

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i < n; i++){
          // if nothing is in stack than just push 
            if(st.empty()){
                st.push(i);
            }
            else{
              // otherwise pop ane calculate the max Area for already visited elements --> ONLY if current element is smaller than previous
                while(!st.empty() && heights[st.top()] > heights[i]){
                    int topi = st.top();
                    st.pop();
                    int width;
                  // afting popping out topi from stack, if we have empty stack --> it means it has no previous smaller element
                    if(st.empty()) {
                        width = i;  // calculate width
                    }
                      // otherwise top of stack is its previous smaller element 
                    else {
                        width = i - st.top() - 1;  // calculate width
                    }
                    maxArea = max(maxArea, width*heights[topi]); // calculate maxArea
                }
                st.push(i);  // then push current element
            }
        }

      // if after traversing through all the element stack still not empty it means top element has no next smaller element
        while(!st.empty()){
          // take out top element
            int topi = st.top();
            st.pop();
          // if stack is emepty of taking it out --> its last element --> so it doesnot has previous smaller as well so width will be n
            int width;
            if(st.empty()) {
                width = n;
            }
             // otherwise if stack is not empty after taking it out ---> it has previous smaller element on top of stack --> calcualte width now 
            else {
                width = n - st.top() - 1;
            }
          // then calcualte maxArea at last 
            maxArea = max(maxArea, width*heights[topi]);
        }

        return maxArea;  // return maxArea
    }
};

// METHOD 3: Same method as above just little cleaner version ---> with NSE and PSE marking

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty() && heights[st.top()] > heights[i]){
                    int element = st.top();
                    st.pop();
                    int NSE = i;
                    int PSE = (st.empty() ? -1 : st.top());
                    int width = NSE - PSE - 1;
                    maxArea = max(maxArea, width*heights[element]);
                }
                st.push(i);
            }
        }

        while(!st.empty()){
            int element = st.top();
            st.pop();
            int NSE = n;
            int PSE = (st.empty() ? -1 : st.top());
            int width = NSE - PSE - 1;
            maxArea = max(maxArea, width*heights[element]);
        }

        return maxArea;
    }
};
