// Question Link: https://leetcode.com/problems/word-break/description

// METHOD 1: Using Recursion    --->   TLE

class Solution {
public:
    bool solve(int idx, string &s, unordered_map<string, bool> &mp, int n){
        if(idx == n){
            return true;
        }
        for(int l = 1; l <= n; l++){
            string temp = s.substr(idx, l);
            if(mp[temp] && solve(idx+l, s, mp, n)){
                return true;
            }
        }

        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int ns = s.length();
        int n = wordDict.size();
        unordered_map<string, bool> mp;
        for(int i = 0; i < n; i++){
            mp[wordDict[i]] = true;
        }
        return solve(0, s, mp, ns);
    }
};

// METHOD 2: Using Memoization 

class Solution {
public:
    int dp[301];
    bool solve(int idx, string &s, unordered_map<string, bool> &mp, int n){
        if(idx == n){
            return true;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        for(int l = 1; l <= n; l++){
            string temp = s.substr(idx, l);
            if(mp[temp] && solve(idx+l, s, mp, n)){
                return true;
            }
        }

        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int ns = s.length();
        int n = wordDict.size();
        memset(dp, -1, sizeof(dp));
        unordered_map<string, bool> mp;
        for(int i = 0; i < n; i++){
            mp[wordDict[i]] = true;
        }
        return solve(0, s, mp, ns);
    }
};

