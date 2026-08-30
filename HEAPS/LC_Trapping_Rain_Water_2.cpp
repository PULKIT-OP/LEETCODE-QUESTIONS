// Question Link: https://leetcode.com/problems/trapping-rain-water-ii/description/


// METHOD 1: 

class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<PP>> pq;

        vector<vector<bool>> visited(m, vector<bool> (n, false));

        // leftmost col and rightmost col
        for(int row = 0; row < m; row++){
            for(int col : {0, n-1}){
                pq.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }
        // top and bottom row
        for(int col = 0; col < n; col++){
            for(int row : {0, m-1}){
                pq.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int water = 0;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int h = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;

            for(auto &d : directions){
                int x_ = x + d[0];
                int y_ = y + d[1];

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && !visited[x_][y_]){
                    water += max(h - heightMap[x_][y_], 0);
                    pq.push({max(h, heightMap[x_][y_]), {x_, y_}});
                    visited[x_][y_] = true;
                }

            }
        }

        return water;
    }
};
