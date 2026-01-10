// Question Link: 

// WRAP TEXT ON KRKE DEKHO PLZZ -----> PLEASE USE WRAP TEXT

// METHOD 1: Recursion Method ----> REHNE DE LALA TLE AAEGA
// Main logic behind this method is either you can take curr element or you can skip it, but but but if you want to take current element for that you have to more options 
// Either you will add that to your final answer or you will subtract that number from your final answer
// To check addition or subtraction you will pass a boolean

class Solution {
public:
    long long solve(vector<int> &nums, int i, bool even){
        if(i >= nums.size()){
            return 0;
        }
      // initializing variables 
        long long take;
        long long skip;
      // if curren index is not even then subtract it from your answer
        if(!even){
            take = -nums[i] + solve(nums, i+1, true);
        }
      // otherwise add that to your final answer
        else{
            take = nums[i] + solve(nums, i+1, false);
        }

      // if you want to skip than your boolean will be same
        skip = solve(nums, i+1, even);

      // return maximum of take and skip
        return max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        return solve(nums, 0, true);
    }

};


// METHOD 2: MEMOIZATION ---> Logic remains same Just storing repeating answers for future usage
//

class Solution {
public:
// initializing dp vector
    vector<vector<long long>> dp;
    long long solve(vector<int> &nums, int i, bool even){
        if(i >= nums.size()){
            return 0;
        }
      // if you already have best answer for this index then return 
        if(dp[i][even] != -1){
            return dp[i][even];
        }
        long long take;
        long long skip;
        if(!even){
            take = -nums[i] + solve(nums, i+1, true);
        }
        else{
            take = nums[i] + solve(nums, i+1, false);
        }

        skip = solve(nums, i+1, even);

        return dp[i][even] = max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
      // updating dp array size according to question
        dp.resize(n+1, vector<long long> (2, -1));

        return solve(nums, 0, true);
    }
};


// METHOD 3: BOTTOM UP
// Here also logic remains same that we have two choices either take or skip ---> in each iteration we have have two choices either its odd length sequence or even length sequence
// So for each itereation we are updating two variables odd and even ----> for both of them we are taking maximum of take and skip
// Assuming 0 ---> even  and   1 ---> odd

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
      // initialize dp vector
        vector<vector<long long>>dp (n+1, vector<long long>(2, 0));
      // start iteration from 1 to avoid error
        for(int i = 1; i <= n; i++){
          // if current index make odd length then take i-1th index of dp and subtract current index, and if you are skipping current index then add i-1th value                in current index but with current lenght flag
          // if current index make even length then take i-1th index of dp and add current index
          // bhai is cheez pr jyada dhyaan dena ---> dobara se sun, agar current element milakar even length ho jaa raha hai it means current element ko lene               se pehle odd length raha hoga. isiliye take krne ke time pe i-1th ko reverse krke lete hain. and agar current element ko milaakr even length hua hai to            current element odd index pr hoga na. example dekh : 5, 6, 7, 8 ---> yaha pr 8 ko milakr dekhega to length toh even hai pr 8 ka index kya hai?? ODD                hai ---> and odd index ko subtract krna tha. AB SAMAJH AAYA???
            dp[i][1] = max(dp[i-1][0] - nums[i-1], dp[i-1][1]);
            dp[i][0] = max(dp[i-1][1] + nums[i-1], dp[i-1][0]);
        }

      // at last index you will have final value so return the maximum value bw even and odd
        return max(dp[n][0], dp[n][1]);
    }

};
