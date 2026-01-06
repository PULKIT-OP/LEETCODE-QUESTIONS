// Question Link: 

// METHOD 1: Recursion method ---> 2^n complexity   ----> This method is not recommended ---> TLE aaega LAADLE
// Going from ground to target stair
class Solution {
public:
    int solve(int n, int target){
        if(n > target){
            return 0;
        }
        if(n == target){
            return 1;
        }
        int one = solve(n+1, target);
        int two = solve(n+2, target);

        return one + two;
    }
    int climbStairs(int n) {
        
        return solve(0, n);
    }
};

// Going towards ground from target stair

class Solution {
public:
    int solve(int n){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        int one = solve(n-1, target);
        int two = solve(n-2, target);

        return one + two;
    }
    int climbStairs(int n) {
        
        return solve(n);
    }
};

// METHOD 2: MEMOIZATION 
// top to bottom method

class Solution {
public:
    vector<int> dp;
    int solve(int n){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }
        int one = solve(n-1);
        int two = solve(n-2);

        return dp[n] = one + two;
    }
    int climbStairs(int n) {
        dp.resize(n+1, -1);
        return solve(n);
    }
};

// bottom to top method:
class Solution {
public:
    vector<int> dp;
    int solve(int n, int target){
        if(n > target){
            return 0;
        }
        if(n == target){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }
        int one = solve(n+1, target);
        int two = solve(n+2, target);

        return dp[n] = one + two;
    }
    int climbStairs(int n) {
        dp.resize(n+1, -1);
        return solve(0, n);
    }
};



// METHOD 3: BOTTOM UP APPROACH ---> small problem to big problem 

class Solution {
public:
    vector<int> dp;
    int climbStairs(int n) {
        if(n <= 3){
            return n;
        }

        dp.resize(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];

    }
};

// METHOD 4: CONSTANT SPACE SOLUTION ---> With 3 Variables

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3){
            return n;
        }

        int a = 1;
        int b = 2;
        int c;

        for(int i = 3; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};
