// Question Link: https://leetcode.com/problems/string-to-integer-atoi/description/


// METHOD 1: There is nothing much to explain, its self explanatory and procedural problem

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();

        int i = 0;
        while(i < n && s[i] == ' '){
            i++;
        }

        int sign = 1;
        if(i < n){
            if(s[i] == '-'){
                sign = -1;
                i++;
            }
            else if(s[i] == '+'){
                sign = 1;
                i++;
            }
        }

        while(i < n && s[i] == '0'){
            i++;
        }

        long long final_num = 0;
        while(i < n){
            if(s[i] < '0' || s[i] > '9'){
                break;
            }
            int num = s[i] - '0';
            
            final_num = (final_num * 10) + num;

          // since we just have to return 32bit integer so if our answer becomes greater than 32bit integer we return INT_MAX or INT_MIN instantly
            if(sign == 1 && final_num > INT_MAX){
                return INT_MAX;
            }

            if(sign == -1 && -final_num < INT_MIN){
                return INT_MIN;
            }
            i++;
        }

        return final_num * sign;
    }
};
