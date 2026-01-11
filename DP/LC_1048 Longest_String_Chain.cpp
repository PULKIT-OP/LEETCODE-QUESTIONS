// Question Link: https://leetcode.com/problems/longest-string-chain/

// METHOD 1: RECURSION ---> TLE aaega LAADLE

class Solution {
public:
// Function to check if the word is predecessor of current word
    bool isPred(string &curr, string &prev){
        int N = curr.length();
        int M = prev.length();
      // if Length of previous word should be less than current word and absolute difference bw length of both the words must be 1.
      // Are bhai agar M bada ho jaega N se, iska matlab vo predecessor hai hi nahi. predecessor me toh ek letter kam hona tha na?? bhul gya??
        if(M >= N || abs(N-M) != 1){
            return false;
        }

        int i = 0;
        int j = 0;

      // run while loop 
        while(i < M && j < N){
          // if letters are matching increment indexes 
            if(curr[j] == prev[i]){
                i++;
            }
            j++;
        } 

      // this is very important lets say you passes all the previous conditions M is less than N by 1 and all
      // but when you entered while loop you iterated i on previous word and j on current word.
      // in while loop you are increment j always but you increment i when you find a common letter ---> it means if you didnot find any letter your iteration wiht j will end soon but your i will not end 
      // So after while loop if you have visited all the letter of previous word means all the letters were present in current word menas its a predecessor
      // But if you have not visited all the letters it means its not a predecessor.
        return i == M;
    }

// Normal LIS Code 
    int solve(vector<string> &words, int i, int prev){
        if(i >= words.size()){
            return 0;
        }

        int take = 0;
        int skip = 0;

      // Here checking if prev is -1 or prev word is predecessor of ith word
        if(prev == -1 || isPred(words[i], words[prev])){
            take = 1 + solve(words, i+1, i);
        }
      
        skip = solve(words, i+1, prev);

        return max(take, skip);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        if(n == 1){
            return words[0].length();
        }

      // Lambda function for sorting based on length of string
        auto lambda = [](string s1, string s2){
            return s1.length() < s2.length();
        };

        sort(words.begin(), words.end(), lambda);

        return solve(words, 0, -1);
    }
};




// METHOD 2: MEMOIZATION  --> EXACT SAME AS ABOVE Just memoized version AS SAME AS LIS

class Solution {
public:
    int dp[1001][1001];
    bool isPred(string &curr, string &prev){
        int N = curr.length();
        int M = prev.length();
        if(M >= N || abs(N-M) != 1){
            return false;
        }

        int i = 0;
        int j = 0;

        while(i < M && j < N){
            if(curr[j] == prev[i]){
                i++;
            }
            j++;
        } 

        return i == M;
    }
    int solve(vector<string> &words, int i, int prev){
        if(i >= words.size()){
            return 0;
        }

        if(prev != -1 && dp[i][prev] != -1){
            return dp[i][prev];
        }
        int take = 0;
        int skip = 0;

        if(prev == -1 || isPred(words[i], words[prev])){
            take = 1 + solve(words, i+1, i);
        }
        skip = solve(words, i+1, prev);

        if(prev != -1){
            dp[i][prev] = max(take, skip);
        }

        return max(take, skip);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        if(n == 1){
            return words[0].length();
        }

        memset(dp, -1, sizeof(dp));

        auto lambda = [](string s1, string s2){
            return s1.length() < s2.length();
        };

        sort(words.begin(), words.end(), lambda);

        return solve(words, 0, -1);
    }
};


// METHOD 3: BOTTOM UP --> LIS

class Solution {
public:

// Same function to check if word is predecessor or not
    bool isPred(string &curr, string &prev){
        int N = curr.length();
        int M = prev.length();
        if(M >= N || abs(N-M) != 1){
            return false;
        }

        int i = 0;
        int j = 0;

        while(i < M && j < N){
            if(curr[j] == prev[i]){
                i++;
            }
            j++;
        } 

        return i == M;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        if(n == 1){
            return words[0].length();
        }

      // lambda function
        auto lambda = [](string s1, string s2){
            return s1.length() < s2.length();
        };

      // Sorting based on string length
        sort(words.begin(), words.end(), lambda);

        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
              // ith word is current word and jth word is previous word 
                if(isPred(words[i], words[j])){
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxi = max(maxi, dp[i]);
                }
            }
        }

        return maxi;
    }
};
