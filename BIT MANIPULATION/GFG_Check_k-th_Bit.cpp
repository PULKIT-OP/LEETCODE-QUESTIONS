// Question Link: https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

// METHOD 1: Using left shift:
class Solution {
  public:
    bool checkKthBit(int n, int k) {
        int m = 1 << k;
        return n & m;
    }
};

// METHOD 2: Using right shift: 

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        n = n >> k;
        return n & 1;
    }
};
