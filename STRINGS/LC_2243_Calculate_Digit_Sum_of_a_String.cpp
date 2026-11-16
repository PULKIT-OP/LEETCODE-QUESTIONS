// Question Link: https://leetcode.com/problems/calculate-digit-sum-of-a-string/description


// METHOD 1: Normal Method ---> Nothing to explain, just do whatever is asked in the question 

class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();

        if(n <= k){
            return s;
        }

        while(s.length() > k){
            int len = s.length();

            int i = 0;
            string tempStr = "";
            while(i+k-1 < len){
                string ss = s.substr(i, k);
                int sum = 0;
                for(auto &ch : ss){
                    sum += (ch - '0');
                }
                tempStr += to_string(sum);
                i += k;
            }
            int sz = min(k, len-i);
            if(sz > 0){
                string ss = s.substr(i, sz);
                int sum = 0;
                for(auto &ch : ss){
                    sum += (ch - '0');
                }
                tempStr += to_string(sum);
            }
            s = tempStr;
            tempStr = "";
        }

        return s;
    }
};
