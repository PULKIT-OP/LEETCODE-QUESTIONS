// Question Link: https://leetcode.com/problems/minimum-xor-path-in-a-grid/description/


// METHOD 1: Using BOTTOM UP APPROACH WITH BITSET 

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bitset<1024>>> dp(m+1, vector<bitset<1024>>(n+1));
        dp[0][0][grid[0][0]] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    continue;
                }
      
                bitset<1024> left;
                bitset<1024> up;

                if(i > 0){
                    up = dp[i-1][j];
                }
                if(j > 0){
                    left = dp[i][j-1];
                }

                bitset<1024> combined = up | left;

                for(int bit = 0; bit < 1024; bit++){
                    if(combined[bit]){
                        int xorr = grid[i][j] ^ bit;
                        dp[i][j][xorr] = 1;
                    }
                }
            }
        } 

        for(int i = 0; i < 1024; i++){
            if(dp[m-1][n-1][i] == 1){
                return i;
            }
        }

        return -1;
    }
};
