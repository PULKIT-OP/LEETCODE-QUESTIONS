// Question Link: https://leetcode.com/problems/fibonacci-number/description/


// METHOD 1: Brute force method Using recursion

class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }

        int ans = fib(n-1) + fib(n-2);

        return ans;
    }
};


// METHOD 2: After Memoization ----> Means, storing repeating values for future use

class Solution {
public:
    vector<int> dp;
    int solve(int n){
        if(n <= 1){
            return n;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = solve(n-1) + solve(n-2);
    }
    int fib(int n) {
        dp.resize(n+1, -1);

        return solve(n);
    }
};


// METHOD 3: BOTTOM UP APPROACH ---> O(n) 
class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

// METHOD 4 : With constant space
// In this question we just need previous two values to calculate current value so we will just store those previous two values 

class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        int a = 0;
        int b = 1;
        int c = 0;
      // we are traversing 1 to n-1 times because we already have first value so we dont have to calculate that
        for(int i = 1; i < n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
