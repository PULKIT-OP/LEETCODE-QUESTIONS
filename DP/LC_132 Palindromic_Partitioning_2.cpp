// Question Link: https://leetcode.com/problems/palindrome-partitioning-ii/description/

// METHOD 1:  Recursion + Memoization ---> TLE AAEGA

class Solution {
public:
  // To store Palindrome 
    int dp[2001][2001]; 
  // To store cuts 
    int dp2[2001][2001];
    bool isPalind(string &s, int i, int j){
        if(i >= j){
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == s[j]){
            return dp[i][j] = isPalind(s, i+1, j-1);
        }

        return dp[i][j] = false;
    }
    int solve(string &s, int i, int j){
        if(i >= s.length()){
            return 0;
        }
        if(dp2[i][j] != -1){
            return dp2[i][j];
        }
        int left = 0;
        int right = 0;
        int count = INT_MAX;
        if(isPalind(s, i, j)){
            return dp2[i][j] = 0;
        }
        else{
            int temp = 0;
            for(int k = i; k < j; k++){
                left = solve(s, i, k);
                right = solve(s, k+1, j);
                temp = 1 + left + right;
                count = min(count, temp);
            }

        }

        return dp2[i][j] = count;
    }
    int minCut(string s) {
        int n = s.length();

        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));

        return solve(s, 0, n-1);
    }
};


// METHOD 2: BOTTOM UP ----> USING BLUE PRINT

class Solution {
public:
    int minCut(string s) {
        int n = s.length();

      // Filling up the Palindrome dp ---> USING BLUE PRINT
        vector<vector<bool>> t(n+1, vector<bool>(n+1, false));
        for(int i = 0; i < n; i++){
            t[i][i] = true;
        }
      
        for(int L = 2; L <= n; L++){
            for(int i = 0; i+L-1 < n; i++){
                int j = i+L-1;
                if(i == j){
                    t[i][j] = true;
                }
                if(i+1 == j){
                    t[i][j] = (s[i] == s[j]);
                }
                else{
                    t[i][j] = ((s[i] == s[j]) && t[i+1][j-1]);
                }
            }
        }

      // Now Main logic starts ----> Actual Problem solving 
      // Making dp vector to store number of cuts required
      // STATE DEFINE : dp[i] ----> number of cuts required from 0 to ith index to make it palindrome
        vector<int> dp(n);

      // Iterating from 0th index to nth index 
        for(int i = 0; i < n; i++){
          // If substring 0th index to ith index is palindrome then 0 cuts required. So, dp[i] = 0
            if(t[0][i]){
                dp[i] = 0;
            }
            else{
              // Otherwise first store infinite value in dp to that you can find the minimum value after comparison
                dp[i] = INT_MAX;
              // Now making cuts from 0th index to i-1th index to check which one is janvin(minimum)
                for(int k = 0; k < i; k++){
                  // If k+1th index to ith index is palindrome and along with 1 + total number of cuts required till Kth index is less than total number of cuts required till ith index then uptade dp[i] with smaller value
                  // Bhai in simple words ---> you checked index i tak palindrome hai ki nahi ---> agar hai to sorted hai, and agar nahi ---> toh cut marne padenge
                  // Toh cut kaha mar sakte hain index 0 se lekar jaha tak tune abhi iterate kiya hai, vahi tak to marega cut usse aage thodi jaega. YAHA TAK OK HAI??
                  // Ab tu jaha cut maarne vala hai usse pehle ye check kar ki uske aage ka maal(k+1 to i) palindrome hai ki nahi agar nahi toh cut marne ki zarurt hi nahi na bhai, kyu faltu me cost badhana
                  // Agar palindrome hai toh ab ye dekh ki jaha tune cut maara hai usme agar ek cut jod dein toh kya voh or jis index pe tu abhi hai uspe jo cut lage hue hai usse kam hai if yes toh update kr de small vala abhi vale index pr
                  
                    if(t[k+1][i] && ((1 + dp[k]) < dp[i])){
                        dp[i] = 1 + dp[k];
                    }
                }
            }
        }

      // And at last total number of janvin cuts required will be stored as our state definition says
        return dp[n-1];
    }
};

// I couldn't explained in better way but i surely will return and explain it best way possible. Right now i know the algo and know how it works but i'm not getting feel of the working of this algorithm I just know how it works
