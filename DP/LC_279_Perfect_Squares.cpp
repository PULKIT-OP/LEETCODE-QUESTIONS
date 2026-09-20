// Question Link: https://leetcode.com/problems/perfect-squares/description/

// METHOD 1: Using Recursion ====> TLE

class Solution {
public:
    long long solve(int n){
        if(n == 0){
            return 0;
        }
        long long finalAns = INT_MAX;
        for(int i = 1; i*i <= n; i++){
            long long result = 1 + solve(n - i*i);
            finalAns = min(result, finalAns);
        }

        return finalAns;
    }
    int numSquares(int n) {
        return solve(n);
    }
};


// METHOD 2: Memoization

class Solution {
public:
    int dp[10001];
    long long solve(int n){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        long long finalAns = INT_MAX;
        for(int i = 1; i*i <= n; i++){
            long long result = 1 + solve(n - i*i);
            finalAns = min(result, finalAns);
        }

        return dp[n] = finalAns;
    }
    int numSquares(int n) {
        for(int i = 0; i < 10001; i++){
            dp[i] = -1;
        }
        return solve(n);
    }
};
