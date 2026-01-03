// Question Link: https://leetcode.com/problems/map-of-highest-peak/

// METHOD 1: Using MULTISOURCE BFS APPROACH

class Solution {
public:
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        queue<pair<int, int>> que;
        int land = 0;
        vector<vector<int>> result(n, vector<int> (m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isWater[i][j] == 1){
                    que.push({i, j});
                    result[i][j] = 0;
                }
                if(isWater[i][j] == 0){
                    land++;
                }
            }
        }

        int depth = 1;
        while(!que.empty()){
            int size = que.size();

            while(size--){
                int x = que.front().first;
                int y = que.front().second;
                que.pop();

                for(int i = 0; i < 4; i++){
                    int new_x = x + direction[i][0];
                    int new_y = y + direction[i][1];

                    if(new_x < n && new_x >= 0 && new_y < m && new_y >= 0 && result[new_x][new_y] == -1){
                        result[new_x][new_y] = depth;
                        que.push({new_x, new_y});
                    }
                }
            }
            depth++;
        }

        return result;
    }
};
