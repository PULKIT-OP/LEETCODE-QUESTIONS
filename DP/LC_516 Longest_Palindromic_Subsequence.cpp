// Question Link: https://leetcode.com/problems/longest-palindromic-subsequence/description/

// METHOD 1: RECURSION + MEMOIZATION  --->  USING LCS(Longest Common Subsequence)

class Solution {
public:
    int dp_2[1001][1001];
    int n;
    int maxi;
    int solve(string &s1, string &s2, int i, int j){
        if(i >= n || j >= n){
            return 0;
        }
        if(dp_2[i][j] != -1){
            return dp_2[i][j];
        }
        if(s1[i] == s2[j]){
            return dp_2[i][j] = 1 + solve(s1, s2, i+1, j+1);
        }
        else{
            int remove_i = solve(s1, s2, i+1, j);
            int remove_j = solve(s1, s2, i, j+1);

            return dp_2[i][j] = max(remove_i, remove_j);
        }

        return -1;
    }
    int longestPalindromeSubseq(string s) {
        n = s.length();
        string s2 = s;

        reverse(s2.begin(), s2.end());

        memset(dp_2, -1, sizeof(dp_2));

        maxi = -1;
        
        return solve(s, s2, 0, 0);
    }
};


// METHOD 2: 

