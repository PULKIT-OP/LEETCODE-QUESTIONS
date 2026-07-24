// Question Link: https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

// METHOD 1: 

class Solution {
  public:
    string infixToPostfix(string& s) {
        // code here
        int n = s.length();
        stack<char> st;
        string ans = "";
        unordered_map<char, int> mp;
        mp['^'] = 3;
        mp['*'] = 2;
        mp['/'] = 2;
        mp['-'] = 1;
        mp['+'] = 1;
        
        for(int i = 0; i < n; i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
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
                st.pop();
            }
              // For the same left associativity reason
            else if(s[i] == '^'){
                st.push(s[i]);
            }
            else{
                while(!st.empty() && st.top() != '(' && mp[st.top()] >= mp[s[i]]){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};


// METHOD 2: 

class Solution {
  public:
    string infixToPostfix(string& s) {
        // code here
        int n = s.length();
        stack<char> st;
        string ans = "";
        unordered_map<char, int> mp;
        mp['^'] = 3;
        mp['*'] = 2;
        mp['/'] = 2;
        mp['-'] = 1;
        mp['+'] = 1;
        
        for(int i = 0; i < n; i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
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
                st.pop();
            }
            else{
                while(!st.empty() && st.top() != '(') {
                    if(mp[s[i]] > mp[st.top()]) {
                        break; // Current operator has higher precedence
                    }
                    else if(mp[s[i]] == mp[st.top()]) {
                        // For '^', pop only if same precedence (right associativity)
                        // For other operators, pop if same precedence (left associativity)
                        if(s[i] == '^') {
                            break; // Don't pop for right-associative '^'
                        }
                        // For other operators, pop when same precedence
                    }
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
