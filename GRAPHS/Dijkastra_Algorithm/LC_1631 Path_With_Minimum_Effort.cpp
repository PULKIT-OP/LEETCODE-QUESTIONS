// Question Link: https://leetcode.com/problems/path-with-minimum-effort/description/

// METHOD 1: Using DIJKSTRA's Algorithm ---> Priority Queue
class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> direction = {
        {1, 0}, // right
        {-1, 0}, // left
        {0, 1}, // up
        {0, -1} // down
    };
    int minimumEffortPath(vector<vector<int>>& heights) {

      // here is the normal DIJKSTRA till few lines
        int n = heights.size();
        int m = heights[0].size();

        if(n == 0 || m == 0){
            return -1;
        }

      // lambda function to check if the coordinate exist or not, you can make a new global function above 
        auto isSafe = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m;
        };

      // priority queue stuff
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
      
      // tracking minimum cost/effort
        vector<vector<int>> minCost(n, vector<int> (m, INT_MAX));
        minCost[0][0] = 0;

      // run till queue becomes empty
        while(!pq.empty()){
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

          // Not necessary but you can use it to save some time          
            if(x == n-1 && y == m-1){
                return diff;
            }
          // checking other connected cells ---> up down right left
            for(auto &e : direction){
              // coordinates of new cell
                int new_x = x + e[0];
                int new_y = y + e[1];
              // checking if the new cell coordinates are janvin or not
                if(isSafe(new_x, new_y)){
                  // finidng absolute differece between main cell ans its neighbour cell
                    int absDiff = abs(heights[x][y] - heights[new_x][new_y]);
                  // now storing the maximum difference
                    int maxDiff = max(diff, absDiff);
                  // if the minCost of new node is more than maxDiff then update it with maxDiff and push it in queue
                    if(minCost[new_x][new_y] > maxDiff){
                        minCost[new_x][new_y] = maxDiff;
                        pq.push({maxDiff, {new_x, new_y}});
                    }
                }
            }
        }
        // at last return the minCost of last cell ---> as it will be storing the maximum possible effort it requieres to reach this cell
        return minCost[n-1][m-1];
    }
};


// i have doubt in this question i'll be revisiting this question soon, HAPPY NEW YEAR 2026 YAYAYA
