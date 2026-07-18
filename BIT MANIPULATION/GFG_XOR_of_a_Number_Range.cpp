// Question Link: https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1

// METHOD 1: Using Observed Pattern of XOR
// Login behind this is simple --> we have to find XOR from l to r
// we can easily find out xor from 1 to r
// then we jsut do xor from 1 to l-1 
// then xor of both of them
// for exmaple ---> 4 ^ 5 ^ 6 ^ 7 --> this can be written as --> (1 ^ 2 ^ 3)  ^  (1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7)
// 1 ^ 1  2 ^ 2  3 ^ 3 ----> all three gets cancelled out and we get --> 4 ^ 5 ^ 6 ^ 7 --> Our actual answer
class Solution {
  public:
    int findXOR(int l, int r) {
        // XOR from 1 -> r
        int xor_r;
        if(r%4 == 1){
            xor_r = 1;
        }
        else if(r%4 == 2){
            xor_r = r+1;
        }
        else if(r%4 == 3){
            xor_r = 0;
        }
        else{
            xor_r = r;
        }

      // XOR from 1 -> l-1
        int xor_l = 0;
        l--;

        if(l%4 == 1){
            xor_l = 1;
        }
        else if(l%4 == 2){
            xor_l = l+1;
        }
        else if(l%4 == 3){
            xor_l = 0;
        }
        else{
            xor_l = l;
        }

      // XOR of (1 - l-1) ^ (1 - r)
        return xor_r ^ xor_l;
    }
};



// KEY OBSERVATION OF XOR 

XOR from 1 → n follows a pattern based on n % 4:

n % 4 == 0 → n
n % 4 == 1 → 1
n % 4 == 2 → n + 1
n % 4 == 3 → 0
