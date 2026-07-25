// Question Link: https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1

// METHOD 1: 

class Solution {
  public:
    string postToInfix(string &s) {
        // Write your code here
        int n = s.length();
        
        int i = 0;
        stack<string> st;
        while(i < n){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
                st.push(string(1, s[i]));
            }
            else{
                string op2 = st.top();
                st.pop();
                string op1 = st.top();
                st.pop();
                string ans = "(";
                ans += op1;
                ans += s[i];
                ans += op2;
                ans += ")";
                st.push(ans);
            }
            i++;
        }
        
        return st.top();
    }
};
