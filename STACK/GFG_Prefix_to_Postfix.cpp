// Question Link: https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1

// METHOD 1: 

class Solution {
  public:
    string preToPost(string &s) {
        // code here
        int n = s.length();
        int i = n-1;
        stack<string> st;
        
        while(i >= 0){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
                st.push(string(1, s[i]));
            }
            else{
                string top1 = st.top();
                st.pop();
                string top2 = st.top();
                st.pop();
                string ans = "";
                ans = ans + top1 + top2 + s[i];
                st.push(ans);
            }
            i--;
        }
        
        return st.top();
    }
};
