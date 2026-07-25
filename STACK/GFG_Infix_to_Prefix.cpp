// Question Link: https://www.geeksforgeeks.org/problems/infix-to-prefix-notation/1

// METHOD 1: Using Stack

class Solution {
  public:
    string infixToPrefix(string &s) {
        // code here
        int n = s.length();
        reverse(s.begin(), s.end());
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                s[i] = ')';
            }
            else if(s[i] == ')'){
                s[i] = '(';
            }
        }
        unordered_map<char, int> mp;
        mp['^'] = 3;
        mp['*'] = 2;
        mp['/'] = 2;
        mp['-'] = 1;
        mp['+'] = 1;
        string ans = "";
        stack<char> st;
        int i = 0;
        while(i < n){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
                ans.push_back(s[i]);
            }
            else if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans.push_back(st.top());
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                if(s[i] == '^'){
                    while(!st.empty() && mp[s[i]] <= mp[st.top()]){
                        ans.push_back(st.top());
                        st.pop();
                    }
                }
                else{
                    while(!st.empty() && mp[s[i]] < mp[st.top()]){
                        ans.push_back(st.top());
                        st.pop();
                    }
                }
                st.push(s[i]);
            }
            
            i++;
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
