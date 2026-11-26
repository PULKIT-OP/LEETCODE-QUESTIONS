// Question Link: https://leetcode.com/problems/stone-removal-game/description


// MEHTOD 1: 
// Odd steps ---> Alice can play her move
// Even steps ---> Bob can play his move
// whoever misses his/her chance loses
class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        int steps = 0;

        while(n >= take){
            n -= take;
            take--;
            steps++;
        }

        return steps%2 == 0 ? false : true;
    }
};
