// Question Link: https://leetcode.com/problems/minimum-path-sum/description/


// METHOD 1: RECURSION + MEMOIZATION

    int m;
    int n;
    int dp[201][201];
    int solve(vector<vector<int>>& grid, int i, int j){
        if(i >= m || j >= n){
            return INT_MAX;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == m-1 && j == n-1){
            return dp[i][j] = grid[i][j];
        }

        int right = solve(grid, i+1, j);
        int down = solve(grid, i, j+1);

        return dp[i][j] = grid[i][j] + min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(grid, 0, 0);
    }
};

// METHOD 2: USING GRAPH ----> USING BFS  --->  NOT Recommended, Just for practice purpose

class Solution {
public:
    vector<vector<int>> direction = {{1, 0}, {0, 1}};
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> minDist(m, vector<int>(n, INT_MAX));
        minDist[0][0] = grid[0][0];
        queue<pair<int, int>> que;
        que.push({0, 0});

        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            int cost = minDist[x][y];
            que.pop();

            for(auto &e : direction){
                int x_ = x + e[0];
                int y_ = y + e[1];
                if(x_ >= m || y_ >= n){
                    continue;
                }
                int cost_ = grid[x_][y_];

                if(cost + cost_ < minDist[x_][y_]){
                    minDist[x_][y_] = cost + cost_;
                    que.push({x_, y_});
                }
            }
        }

        return minDist[m-1][n-1];
    }
};

// METHOD 3: BOTTOM UP 

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int j = 1; j < n; j++){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m-1][n-1];
    }
};
