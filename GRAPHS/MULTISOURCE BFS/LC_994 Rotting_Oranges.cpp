// Question Link: https://leetcode.com/problems/rotting-oranges/


// METHOD 1: Using MULTISOURCE BFS ALGORITHM: It says just push all the sources in queue in starting and rest remains the same

class Solution {
public:
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

      // Pushing Rotted Oranges in Queue in starting
        queue<pair<int, int>> que;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    que.push({i, j});
                }
            }
        }

      // Now Normal BFS
        int time = 0;
        while(!que.empty()){
            int size = que.size();
            bool rotted = false;

            while(size--){
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                for(int i = 0; i < 4; i++){
                    int new_x = x + direction[i][0];
                    int new_y = y + direction[i][1];

                    if(new_x < n && new_x >= 0 && new_y < m && new_y >= 0 && grid[new_x][new_y] == 1){
                        grid[new_x][new_y] = 2;
                        que.push({new_x, new_y});
                        rotted = true;
                    }
                }
            }
          // incrementing time when we find any rotted orange
            if(rotted){
                time++;
            }
        }

      // Now checking if we have any fresh orange if yes ---> return -1
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return time;
    }
};
