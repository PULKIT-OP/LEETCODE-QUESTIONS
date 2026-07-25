// Question Link: https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1

// METHOD 1: 

class Solution {
  public:
    string postToPre(string s) {
        // code here
        int n = s.length();
        stack<string> st;
        
        int i = 0;
        while(i < n){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
                st.push(string(1, s[i]));
            }
            else{
                string ans = "";
                string top1 = st.top();
                st.pop();
                string top2 = st.top();
                st.pop();
                
                ans = ans + s[i] + top2 + top1;
                st.push(ans);
            }
            i++;
        }
        
        return st.top();
    }
};
