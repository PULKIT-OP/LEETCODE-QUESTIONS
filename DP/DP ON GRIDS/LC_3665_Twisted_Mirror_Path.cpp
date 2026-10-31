// Question Link: https://leetcode.com/problems/twisted-mirror-path-count/



// METHOD 1: Using BFS with some tweaks
class Solution {
public:
    int m;
    int n;
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int solve(int i, int j, int dir, vector<vector<int>>& grid){
        if(i >= m || j >= n){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }

        if(dir >= 0){
            if(dp[i][j][dir] != -1){
                return dp[i][j][dir];
            }
        }

        int count = 0;
        // left -> 1, top -> 0, dir means kaha se entry maar raha hun, left se ya fir right se
        if(grid[i][j] == 1){
            if(dir == 0){
                count = solve(i, j+1, 1, grid);
            }
            else{
                count = solve(i+1, j, 0, grid);
            }
        }
        else{
            count = solve(i+1, j, 0, grid);
            count = (count + solve(i, j+1, 1, grid)) % MOD;
        }

        if(dir >= 0){
            return dp[i][j][dir] = count;
        }

        return count;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(0, 0, -1, grid);
    }
};
