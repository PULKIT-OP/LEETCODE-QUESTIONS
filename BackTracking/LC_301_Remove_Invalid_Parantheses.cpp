// Question Link: https://leetcode.com/problems/remove-invalid-parentheses/description


// METHOD 1: Using Backtracking

class Solution {
public:
    int n;
    int maxLen = 0;
    void solve(int idx, string &s, string &curr, int count, unordered_set<string> &result){
        if(count < 0){
            return;
        }
        if(idx == n){
            if(count == 0){
                if(curr.length() > maxLen){
                    maxLen = curr.length();
                    result.clear();
                    result.insert(curr);
                }
                else if(curr.length() == maxLen){
                    result.insert(curr);
                }
            }
            return;
        }

        if(s[idx] != '(' && s[idx] != ')'){
            curr += s[idx];
            solve(idx+1, s, curr, count, result);
            curr.pop_back();
            return;
        }

        curr += s[idx];
        if(s[idx] == '('){
            count++;
        }
        else if(s[idx] == ')'){
            count--;
        }
        solve(idx+1, s, curr, count, result);
        if(s[idx] == '('){
            count--;
        }
        else if(s[idx] == ')'){
            count++;
        }
        curr.pop_back();
        solve(idx+1, s, curr, count, result);
    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();

        string curr = "";
        unordered_set<string> result;
        solve(0, s, curr, 0, result);

        vector<string> final_result;
        for(auto e : result){
            final_result.push_back(e);
        }

        return final_result;
    }
};
