// Question Link: https://leetcode.com/problems/generate-parentheses/description/


// METHOD 1: BRUTE FORCE METHOD but works

class Solution {
public:
bool isValid(string s) {
        int n = s.length();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                count++;
            }
            else{
                if(count == 0){
                    return false;
                }
                else{
                    char ch = s[i];
                    if(ch == ')'){
                        count--;
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        return count == 0;
    }
    void solve(int n, vector<string> &result, string s){

      // base case
        if(n == 0){
            if(isValid(s)){
                result.push_back(s);
            }
            return;
        }
        
        s.push_back('(');
        solve(n-1, result, s);
        s.pop_back();
        if(s.length() != 0){
            s.push_back(')');
            solve(n-1, result, s);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
      
        solve(2*n, result, s);

        return result;
    }
};

// METHOD 2:

class Solution {
public:
    void solve(int n, int open, int close, vector<string> &result, string s){

        if(s.length() == 2*n){
            result.push_back(s);
            return;
        }

        if(open < n){
            s.push_back('(');
            solve(n, open+1, close, result, s);
            s.pop_back();
        }

        if(close < open){
            s.push_back(')');
            solve(n, open, close+1, result, s);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        solve(n, 0, 0, result, s);

        return result;
    }
};
