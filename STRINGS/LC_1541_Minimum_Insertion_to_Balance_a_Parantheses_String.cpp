// Question Link: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/


// METHOD 1:

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();

        int insert = 0;
        int count = 0;
        int i = 0;
        while(i < n){
            if(s[i] == '('){
                count++;
                i++;
            }
            else{
                if(count > 0){
                    count--;
                }
                else{
                    insert++;
                }
                if(s[i+1] == ')'){
                    i+=2;
                }
                else{
                    insert++;
                    i++;
                }
            }
        }

        if(count > 0){
            return insert + (count * 2);
        }

        return insert;
    }
};
