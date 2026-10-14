// Question Link: https://leetcode.com/problems/maximize-sum-of-squares-of-digits/description/


// METHOD 1:

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num * 9){
            return "";
        }
        int totalNines = sum/9;
        int remaining = sum%9;

        string result(totalNines, '9');
        if(remaining > 0){
            result.push_back(remaining + '0');
        }

        result.append(num - result.length(), '0');

        return result;
    }
};
