// Question Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

// METHOD 1: Using DIJKSTRA's Algorithm ---> Priority Queue ----> O(n^2 * logn) complexity


class Solution {
public:
    typedef pair<int, pair<int, int>> P;
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

        if(n == 0 || grid[0][0] != 0){
            return -1;
        }

        auto isSafe = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < n;
        };
        
        priority_queue<P, vector<P>, greater<P>> pq;        // {w, {x, y}}
        pq.push({0, {0, 0}});

        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        cost[0][0] = 0;

        while(!pq.empty()){
            int c = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(auto &e : direction){
                int new_x = x + e[0];
                int new_y = y + e[1];
                int c2 = 1;

                if(isSafe(new_x, new_y) && grid[new_x][new_y] == 0 && c + c2 < cost[new_x][new_y]){
                    cost[new_x][new_y] = c + c2;
                    grid[new_x][new_y] = 1;
                    pq.push({c + c2, {new_x, new_y}});
                }
            }
        }

        if(cost[n-1][n-1] == INT_MAX){
            return -1;
        }

        return cost[n-1][n-1] + 1;
    }
};


// METHOD 2: Using Normal QUEUE ---> it will work because all weights are same or you can say there are no weights

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
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

        if(n == 0 || grid[0][0] != 0){
            return -1;
        }

        auto isSafe = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < n;
        };

        // just changing Priority_Queue to Normal Queue and its function names like front(), rest will be same
        queue<P> pq;        // {w, {x, y}}
        pq.push({0, {0, 0}});

        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        cost[0][0] = 0;

        while(!pq.empty()){
            int c = pq.front().first;
            int x = pq.front().second.first;
            int y = pq.front().second.second;
            pq.pop();

            for(auto &e : direction){
                int new_x = x + e[0];
                int new_y = y + e[1];
                int c2 = 1;

                if(isSafe(new_x, new_y) && grid[new_x][new_y] == 0 && c + c2 < cost[new_x][new_y]){
                    cost[new_x][new_y] = c + c2;
                    grid[new_x][new_y] = 1;
                    pq.push({c + c2, {new_x, new_y}});
                }
            }
        }

        if(cost[n-1][n-1] == INT_MAX){
            return -1;
        }

        return cost[n-1][n-1] + 1;
    }
};
