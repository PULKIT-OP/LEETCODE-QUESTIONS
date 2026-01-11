// Question Link: 

// METHOD 1: RECURSION ---> TLE aaega LALA
// Here M denotes ki kitne numbers available hai, N denotes ki kitni positions available hai means kitna size hai array ka, and K denotes the maximum Serach_Cost
// Is method me hum saari posibility ko check karenge 
// har 

class Solution {
public:
    int M;
    int K;
    int N;
    int solve(int i, int search_cost, int maxSoFar){
      // Agar index last tak pahuch gaya toh check karo kya humko answer mil gaya?? Which is search_cost equal ho gaya ya nahi?? if yes, means humko ek method mil gaya, if not return 0
        if(i == N){
            if(search_cost == K){
                return 1;
            }
            return 0;
        }

      // make variable to store answer
        int result = 0;

      // Run loop to check each number on current index(i) if it is possible or not 
        for(int num = 1; num <= M; num++){
          // if num is greater than maxSoFar means ek greater element mil gaya which means search cost increase ans maxSoFar update for next iteration 
            if(num > maxSoFar){
                result += solve(i+1, search_cost + 1, num);
            }
          // otherwise serach_cost same rahega and maxSoFar bhi same hi rahega bas hum next num check karenge 
            else{
                result += solve(i+1, search_cost, maxSoFar);
            }
        }

        return result;
    }
    int numOfArrays(int n, int m, int k) {
        M = m;
        K = k;
        N = n;
      
        return solve(0, 0, -1);
    }
};

// METHOD 2: MEMOIZATION

class Solution {
public:
    int M;
    int K;
    int N;
    int dp[51][51][101];
    int MOD = 1e9 + 7;
    int solve(int i, int search_cost, int maxSoFar){
        if(i == N){
            if(search_cost == K){
                return 1;
            }
            return 0;
        }

        if(maxSoFar != -1 && dp[i][search_cost][maxSoFar] != -1){
            return dp[i][search_cost][maxSoFar];
        }

        int result = 0;

        for(int num = 1; num <= M; num++){
            if(num > maxSoFar){
                result = (result + solve(i+1, search_cost + 1, num))%MOD;
            }
            else{
                result = (result + solve(i+1, search_cost, maxSoFar))%MOD;
            }
        }

        if(maxSoFar != -1){
            dp[i][search_cost][maxSoFar] = result;
        }

        return result;
    }
    int numOfArrays(int n, int m, int k) {
        M = m;
        K = k;
        N = n;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, -1);
    }
};
