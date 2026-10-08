// Question Link: https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1


// METHOD 1: Recursion + Memoization ---> Only recursion gives TLE
class Solution {
  public:
    int n;
    int dp[101][101];
    int f(int i, int j, vector<int> &arr){
        if(i == j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mini = 1e9;
        for(int k = i; k < j; k++){
            int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr) + f(k+1, j, arr);
            if(steps < mini){
                mini = steps;
            }
        }
        
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        
        return f(1, n-1, arr);
    }
};
