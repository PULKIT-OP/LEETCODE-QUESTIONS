// Question Link: https://leetcode.com/problems/find-the-difference/description/


// METHOD 1: Using Difference in ASCII characters

class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length();
        int m = t.length();
        int s_sum = 0;
        int t_sum = 0;
        for(int i = 0; i < n; i++){
            s_sum += s[i];
        }
        for(int i = 0; i < m; i++){
            t_sum += t[i];
        }

        return static_cast<char>(abs(s_sum - t_sum));
        // or You can use 
        //return (char)(abs(s_sum - t_sum));  both works here
    }
};


// METHOD 2: Propogating the difference METHOD

class Solution {
public:
    char findTheDifference(string s, string t) {
        for(int i = 0; i < s.size(); i++){
            t[i+1] += t[i] - s[i];
        }
        return t[t.size()-1];
    }
};
