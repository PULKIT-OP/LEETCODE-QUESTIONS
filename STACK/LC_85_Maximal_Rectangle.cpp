// Question Link: https://leetcode.com/problems/maximal-rectangle/description/

// METHOD 1: Using Largest rectangle in histogram method

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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> result(n, 0);
        int maxArea = 0;
      // Iterating over each row --> Treating it as a histogram and with each row, incrementing summation
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(matrix[row][col] == '1'){
                    result[col]++;
                }
                else{
                    result[col] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(result));
        }

        return maxArea;
    }
};

// METHOD 2: 

