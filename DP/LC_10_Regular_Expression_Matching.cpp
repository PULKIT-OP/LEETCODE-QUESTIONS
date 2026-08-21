// Question Link: https://leetcode.com/problems/regular-expression-matching/description/

// Question Explanation for '*' part

// '*' itself has no existense, it occurs only if there exist a character before it.
// for example:
// *abc --> not possible
// *a*b --> not possible
// .*ab --> possible
// a*bc --> possible
// abc**de --> possible

// Now comes the tricky part,
// if there is a '*' in string --> it simply means you can repeat character just before '*' any number of times form 0 to infinity according to your need.

// I know you did not understand even I didn't, lets take an example:
// s = abc
// p = a*bc
// here '*' has no value it just tells that, you can repeat 'a' any number of times. But we need only one 'a' which is already there, so we are not gonna repeat 'a' more and we got our answer.

// here is another example:
// s = aaaaaaaabbbbbc
// p = .*bc
// here keep in mind you will treat '.*' as a single entity. And '.' means any random character so multiple copies of any random character.
// or you can say '.*' ---> '', 'a', 'aa', 'aaa', 'aaab', infinity times.

// At last just remember only two line:
// '*' has no existense it depends only on its previous character.
// If there is a '*' in string --> it simply means you can repeat character just before '*' any number of times form 0 to infinity according to your need.

// METHOD 1: Using Recursion

class Solution {
public:
    bool solve(string s, string p){
      // if you reached end of your pattern then you must reach end of your string otherwise return false
        if(p.length() == 0){
            return s.length() == 0;
        }

      // checking if first character matched or not and string lenght if valid --> because if string lenght is not valid then its not feasible to check for first character
        bool first_char_matched = s.length() > 0 && (p[0] == s[0] || p[0] == '.');
      // then check if we have atleast 2 lenght of p or not and if 1st index of patter is * because its the deciding factor what we gonna do next
        if(p.length() >= 2 && p[1] == '*'){
          // if its a star then we have two choices take it or do not take it if you take it then your stirng moves further
          // if you do not take it then your pattern moves two steps forward because now you need to move from first chareacter and the star as well
            bool not_take_star = solve(s, p.substr(2));
            bool take_star = false;
            if(first_char_matched){
                take_star = solve(s.substr(1), p);
            }
            return take_star || not_take_star;
        }

      // if second character is not start then both string and pattern moves forward with one step
        return first_char_matched && solve(s.substr(1), p.substr(1));
    }
    bool isMatch(string s, string p) {
        return solve(s, p);
    }
};

// METHOD 2: Using Recursion but little optimized
// Logic reamins same

class Solution {
public:
    int sn;
    int pn;
    string S;
    string P;
    bool solve(int i, int j){
        if(j == pn){
            return i == sn;
        }

        bool first_char_matched = i < sn && (P[j] == S[i] || P[j] == '.');
        if(j+1 < pn && P[j+1] == '*'){
            bool not_take_star = solve(i, j+2);
            bool take_star = false;
            if(first_char_matched){
                take_star = solve(i+1, j);
            }
            return take_star || not_take_star;
        }
        
        return first_char_matched && solve(i+1, j+1);
    }
    bool isMatch(string s, string p) {
        sn = s.length();
        pn = p.length();
        S = s;
        P = p;
        return solve(0, 0);
    }
};

// METHOD 3: Memoization
// logic remains same

class Solution {
public:
    int dp[21][21];
    int sn;
    int pn;
    string S;
    string P;
    bool solve(int i, int j){
        if(j == pn){
            return i == sn;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        bool first_char_matched = i < sn && (P[j] == S[i] || P[j] == '.');
        if(j+1 < pn && P[j+1] == '*'){
            bool not_take_star = solve(i, j+2);
            bool take_star = false;
            if(first_char_matched){
                take_star = solve(i+1, j);
            }
            return dp[i][j] = take_star || not_take_star;
        }
        
        return dp[i][j] = first_char_matched && solve(i+1, j+1);
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        sn = s.length();
        pn = p.length();
        S = s;
        P = p;
        return solve(0, 0);
    }
};
