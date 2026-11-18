// Question Link: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description


// METHOD 1: Simple and Normal Method nothing serious

class Solution {
public:
    int n;
    int minChanges(string s) {
        n = s.length(); // even
        
        int count = 0;

        for(int i = 0; i < n; i+=2){
            int j = i+1;
            if(s[i] != s[j]){
                count++;
            }
        }

        return count;
    }
};
