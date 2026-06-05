// Question Link: https://leetcode.com/problems/remove-outermost-parentheses/

// METHOD 1: Using stack ----> Extra space
// If stack is empty -> push in stack, if stack is not empty -> push in stack and in ans as well (push in stack if '(' encountered) if '(' then pop from stack and after popping stack becomes empty then do not push in ans otherwise push in ans.
// ans string is your final answer

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int n = s.length();
        int i = 0;
        string ans = "";
        while(i < n){
            if(st.empty()){
                if(s[i] == '('){
                    st.push(s[i]);
                }
            }
            else{
                if(s[i] == '('){
                    st.push(s[i]);
                    ans.push_back(s[i]);
                }
                else{
                    st.pop();
                    if(!st.empty()){
                        ans.push_back(s[i]);
                    }
                }
            }
            i++;
        }

        return ans;
    }
};


// METHOD 2: Without extra space

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();

        int i = 0; 
        int count = 0;  // if '(' count++ and if ')' count--
        string ans = "";
      
        while(i < n){
            if(s[i] == '('){
                if(count != 0){        // count == 0 means either its a starting paranthesis or ending paranthesis ----> so just ignore it
                    ans.push_back(s[i]);
                }
                count++;
            }
            else{
                count--;
                if(count != 0){
                    ans.push_back(s[i]);
                }
            }
            i++;
        }

        return ans;
    }
};
