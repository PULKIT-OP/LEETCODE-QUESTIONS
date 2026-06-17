// Question Link: https://leetcode.com/problems/number-of-enclaves/description/

// METHOD 1: BFS
// This question is just like LEETCODE 130 Dittto same code just with minute changes do that first there is a great explanation

class Solution {
public:
    vector<vector<int>>directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

      // the minute change in border checking there we were checking for 'O' here we are checking for 1
        queue<pair<int, int>> q;
        for(int j = 0; j < n; j++){
            if(grid[0][j] == 1){
                q.push({0, j});
                grid[0][j] = -1;
            }
            if(grid[m-1][j] == 1){
                q.push({m-1, j});
                grid[m-1][j] = -1;
            }
        }
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1){
                q.push({i, 0});
                grid[i][0] = -1;
            }
            if(grid[i][n-1] == 1){
                q.push({i, n-1});
                grid[i][n-1] = -1;
            }
        }

      // Now BFS
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto &d : directions){
                int x_ = x + d[0];
                int y_ = y + d[1];

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid[x_][y_] == 1){  // the minute change
                    q.push({x_, y_});
                    grid[x_][y_] = -1;  // the minute change
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){  // The minute change 
                    ans++;
                }
                if(grid[i][j] == -1){
                    grid[i][j] = 1;
                }
            }
        }

        return ans;
    }
};
