// Question Link: https://leetcode.com/problems/minimum-bishop-moves-to-reach-target/description/


// METHOD 1: 
// There are only 4 cases possible ---> Either target and source are at different color squares or target and Source are same, or Both are on same diagonal or Both are not at the same diagonal

class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sx = source[0];
        int sy = source[1];

        int tx = target[0];
        int ty = target[1];

      // If both Target and Source are on different color square --> then there are no possible moves we can reach target so return -1
        if(((sx + sy) % 2) != ((tx + ty) % 2)){
            return -1;
        }

      // If target and source are at same cell then zero moves we need
        if(sx == tx && sy == ty){
            return 0;
        }

      // if both are on the same diagonal --> we need only one move
        if(abs(sx - tx) == abs(sy - ty)){
            return 1;
        }

      // other wise we need only two moves to reach target from sources, in maximum of two moves we can reach any cell from any cell
        return 2;
    }
};
