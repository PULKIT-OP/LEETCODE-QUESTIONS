// Question Link: https://leetcode.com/problems/reverse-words-in-a-string/

// METHOD 1: Using builtin Funtions ---> stringstream

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        stringstream ss(s);      // It breaks the string in space 
        string token = "";
        string result = "";
        while(ss >> token){
            result = token + " " + result;    // Whatever token i m getting from stringstream, im putting it in front and adding previous result in last and then storing it in result again.
        }

        result.pop_back();    // I got an extra space in last so removing the last index which is space

        return result;
    }
};

//  METHOD 2: Using Two pointers 
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        
        reverse(s.begin(), s.end());
        int l = 0;
        int r = 0;
        int i = 0;

        while(i < n){
            while(i < n && s[i] != ' '){
                s[r] = s[i];
                i++;
                r++;
            }
            if(l < r){
                reverse(s.begin()+l, s.begin()+r);
                s[r] = ' ';
                r++;
                l = r;
            }

            i++;
        }

        return s.substr(0, r-1);
    }
};
