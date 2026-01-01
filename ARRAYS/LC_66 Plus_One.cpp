// Question Link: https://leetcode.com/problems/plus-one/description/

// Using Brute Force Method 
// Handling two 3 cases : 1. we have digits[i] != 9 , 2. digits[i] == 9 , 3. starting element is also 9 then we have to insert 1 at starting 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int i = n-1;
        int carry = 1;

        while(carry != 0 && i >= 0){
            if(digits[i] == 9){
                digits[i] = 0;
                carry = 1;
            }
            else{
                digits[i] += carry;
                carry = 0;
                break;
            }
            i--;
        }
        if(carry != 0){
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};
