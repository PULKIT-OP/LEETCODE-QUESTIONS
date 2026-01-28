// Question Link: https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/

// METHOD 1: RECURSION    --->   TLE 

class Solution {
public:
    int n;
    int solve_1(vector<vector<int>>& fruits){
        int result = 0;
        for(int m = 0; m < n; m++){
            result += fruits[m][m];
        }

        return result;
    }
    int solve_2(int i, int j, vector<vector<int>>& fruits){
        if(i >= n || j >= n || i >= j){
            return 0;
        }

        if(i == n-1 && j == n-1){
            return 0;
        }

        int result = fruits[i][j] + max({solve_2(i+1, j-1, fruits), solve_2(i+1, j, fruits), solve_2(i+1, j+1, fruits)});
        return result;
    }
    int solve_3(int i, int j, vector<vector<int>>& fruits){
        if(i >= n || j >= n || i <= j){
            return 0;
        }

        if(i == n-1 && j == n-1){
            return 0;
        }

        int result = fruits[i][j] + max({solve_3(i-1, j+1, fruits), solve_3(i, j+1, fruits), solve_3(i+1, j+1, fruits)});
        return result;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();

        int child_1 = solve_1(fruits);
        int child_2 = solve_2(0, n-1, fruits);
        int child_3 = solve_3(n-1, 0, fruits);

        return child_1 + child_2 + child_3;
    }
};


// METHOD 2: RECURSION + MEMOIZATION

class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve_1(vector<vector<int>>& fruits){
        int result = 0;
        for(int m = 0; m < n; m++){
            result += fruits[m][m];
            dp[m][m] = result;
        }

        return result;
    }
    int solve_2(int i, int j, vector<vector<int>>& fruits){
        if(i >= n || i < 0 || j >= n || j < 0 || i >= j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(i == n-1 && j == n-1){
            return 0;
        }

        int result = fruits[i][j] + max({solve_2(i+1, j-1, fruits), solve_2(i+1, j, fruits), solve_2(i+1, j+1, fruits)});
        return dp[i][j] = result;
    }
    int solve_3(int i, int j, vector<vector<int>>& fruits){
        if(i >= n || i < 0 || j >= n || j < 0 || i <= j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(i == n-1 && j == n-1){
            return 0;
        }

        int result = fruits[i][j] + max({solve_3(i-1, j+1, fruits), solve_3(i, j+1, fruits), solve_3(i+1, j+1, fruits)});
        return dp[i][j] = result;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();

        memset(dp, -1, sizeof(dp));

        int child_1 = solve_1(fruits);
        int child_2 = solve_2(0, n-1, fruits);
        int child_3 = solve_3(n-1, 0, fruits);

        return child_1 + child_2 + child_3;
    }
};

