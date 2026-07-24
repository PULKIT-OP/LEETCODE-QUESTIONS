// Question Link: https://leetcode.com/problems/valid-parentheses/description/

// METHOD 1: Using Stack

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.length();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
                count++;
            }
            else{
                if(st.empty()){
                    return false;
                }
                else{
                    char ch = s[i];
                    if(st.top() == '(' && ch == ')' || st.top() == '[' && ch == ']' || st.top() == '{' && ch == '}'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        return st.empty();
    }
};
