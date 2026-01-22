// Question Link: https://leetcode.com/problems/palindromic-substrings/description/

// METHOD 1: BRUTE FORCE ---> Find all Substring from the given string  --->  then check each substring if it is palindrome or not

class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }

        return true;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int result = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome(s, i, j)){
                    result++;
                }
            }
        }

        return result;
    }
};


// METHOD 2: MEMOIZATION ---> CAN BE DONE USING ABOVE CODE or WITH RECURSION AS WELL

class Solution {
public:
    int dp[1001][1001];
    int isPalindrome(string &s, int i, int j){
        if(i >= j){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] != s[j]){
            return dp[i][j] = 0;
        }
        
        return dp[i][j] = isPalindrome(s, i+1, j-1);
    }
    int countSubstrings(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        int result = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome(s, i, j)){
                    result++;
                }
            }
        }

        return result;
    }
};


// METHOD 3: BOTTOM UP VERSION    --->  MEMORIZE(UNDERSTAND) THIS BLUE PRINT ---> IT WILL HELP IN SIMILAR KINDA PROBLEMS WHICH USES PALINDROME KINDA STUFF
// STATE DEFINITION ---->  dp[i][j] ---> if substring from index i to index j is palindrome of not  --->  true or false
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int result = 0;
        vector<vector<int>> dp(n, vector<int>(n, false));

      // We will be running loop for all length of substring, from lenght 1 to lenght n  ---> Are bhai substring to kitne bhi length ki ho sakti hai to bas vahi dekh rhe hai 
        for(int L = 1; L <= n; L++){
          // Now running loop from i to n   --->  Means hum har ek index se dekhenge L lenght ka subtring, ki vo palindrome hai ya nahi
            for(int i = 0; (i + L - 1) < n; i++){
              // Calculating jth index --->  we know starting index and we know lenght of substring so, from these info we can get where our jth index will be
                int j = i + L - 1;

              // If i equals j means 1 length of substring ---> always a palindrome 
                if(i == j){
                    dp[i][j] = true;
                }
              // if i + 1 equals j  --->  means it is substring of lenght of 2  ----> Ans for length 2 substring both elements should be equal
                else if(i+1 == j){
                    dp[i][j] = (s[i] == s[j]);
                }
              // if length of substring is more than 2 then come here  --> it is general case  --->  ith ans jth elements should be equal and and saath me unke beech ke jo element hai vo bhi palindrome hone chaiye  --->  If yes then it is PALINDROME
                else{
                    dp[i][j] = ((s[i] == s[j]) && dp[i+1][j-1]);
                }

                if(dp[i][j] == true){
                    result++;
                }
            }
        }

        return result;
    }
};
