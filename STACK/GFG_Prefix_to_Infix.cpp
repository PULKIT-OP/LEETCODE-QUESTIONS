// Question Link: https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

// METHOD 1: Using stack --> (just like post fix to infix)

class Solution {
  public:
    string preToInfix(string &s) {
        // code here
        int n = s.length();
        
        int i = n-1;
        stack<string> st;
        while(i >= 0){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
                st.push(string(1, s[i]));
            }
            else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                string ans = "(";
                ans += op1;
                ans += s[i];
                ans += op2;
                ans += ")";
                st.push(ans);
            }
            i--;
        }
        
        return st.top();
    }
};
