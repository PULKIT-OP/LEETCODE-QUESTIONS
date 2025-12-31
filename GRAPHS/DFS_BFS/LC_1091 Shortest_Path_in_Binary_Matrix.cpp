// Question Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

// METHOD 1: Using BFS    ---> we were able to solve this with bfs because there were no weighted edges (Had weight = 1 for all edges).
// This question can also be solved using DIJKSTRA's Algorithm.

class Solution {
public:
    vector<vector<int>> direction = {
        {1, 0},   // down
        {-1, 0},  // up
        {0, 1},   // right
        {0, -1},  // left
        {1, 1},   // bottom-right
        {1, -1},  // bottom-left
        {-1, 1},  // top-right
        {-1, -1}
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int level = 0;

        if(n == 0 || grid[0][0] != 0){
            return -1;
        }
        
        queue<pair<int, int>> que; // i, j
        que.push({0, 0}); 
        grid[0][0] = 1;

        auto isSafe = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < n;
        };

        while(!que.empty()){
            int N = que.size();

            while(N--){
                int x = que.front().first;
                int y = que.front().second;
                que.pop();

                if(x == n-1 &&  y == n-1){
                    return level + 1;
                }

                for(auto &e : direction){
                    int new_x = x + e[0];
                    int new_y = y + e[1];

                    if(isSafe(new_x, new_y) && grid[new_x][new_y] == 0){
                        grid[new_x][new_y] = 1;
                        que.push({new_x, new_y});
                    }
                }
            }

            level++;
        }

        return -1;
    }
};
