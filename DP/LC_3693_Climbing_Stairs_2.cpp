// Question Link: https://leetcode.com/problems/climbing-stairs-ii/description


// METHOD 1: Using Recursion:   TLE

class Solution {
public:
    int N;
    int solve(int step, vector<int> &costs){
        if(step == N){
            return 0;
        }

        int ans = INT_MAX;

        for(int jump = 1; jump <= 3; jump++){
            int next = step + jump;

            if(next <= N){
                int curr = jump * jump + costs[next-1];
                ans = min(ans, curr + solve(next, costs));
            }
        }

        return ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        N = n;
        return solve(0, costs);
    }
};


// METHOD 2: MEMOIZATION

class Solution {
public:
    int N;
    vector<int> dp;
    int solve(int step, vector<int> &costs){
        if(step == N){
            return 0;
        }

        if(dp[step] != -1){
            return dp[step];
        }
        int ans = INT_MAX;

        for(int jump = 1; jump <= 3; jump++){
            int next = step + jump;

            if(next <= N){
                int curr = jump * jump + costs[next-1];
                ans = min(ans, curr + solve(next, costs));
            }
        }

        return dp[step] = ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        N = n;
        dp.resize(n, -1);
        return solve(0, costs);
    }
};


// METHOD 3: BOTTOM UP

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, 0);
        
        for(int i = n-1; i >= 0; i--){
            int ans = INT_MAX;
            for(int j = i+1; j <= min(n, i+3); j++){
                int cost = costs[j-1] + (j-i)*(j-i) + dp[j];
                ans = min(ans, cost);
            }
            dp[i] = ans;
        }

        return dp[0];
    }
};
