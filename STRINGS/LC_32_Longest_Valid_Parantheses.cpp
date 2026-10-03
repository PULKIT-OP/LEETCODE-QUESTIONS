// Question Link: https://leetcode.com/problems/longest-valid-parentheses/description/


// METHOD 1: Using Iteration

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int open = 0;
        int close = 0;
        int leftToRight = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                open++;
            }
            else{
                close++;
                if(open == close){
                    leftToRight = max(leftToRight, open+close);
                }
                else if(close > open){
                    open = 0;
                    close = 0;
                }
            }
        }

        open = 0;
        close = 0;
        int rightToLeft = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == ')'){
                close++;
            }
            else{
                open++;
                if(open == close){
                    rightToLeft = max(rightToLeft, open+close);
                }
                else if(open > close){
                    open = 0;
                    close = 0;
                }
            }
        }

        return max(leftToRight, rightToLeft);
    }
};
