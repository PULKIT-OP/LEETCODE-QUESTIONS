// Question Link: https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1


// METHOD 1: Normal Method using Recursion

class Solution {
  public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool visited[501][501];
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i >= n || j >= n || i < 0 || j < 0){
            return INT_MAX;
        }
        if(i == n-1 && j == n-1){
            return grid[i][j];
        }
        visited[i][j] = true;
        int ans = INT_MAX;
        for(auto &d : directions){
            int x = i + d[0];
            int y = j + d[1];
            
            if(x < n && x >= 0 && y < n && y >= 0 && !visited[x][y]){
                int sol = solve(x, y, grid);
                if(sol != INT_MAX){
                    ans = min(ans, sol);
                }
            }
        }
        
        visited[i][j] = false;
        
        if(ans == INT_MAX){
            return ans;
        }
        
        return grid[i][j] + ans;
    }
    int minimumCostPath(vector<vector<int>>& grid) {
        // Code here
        n = grid.size();
        memset(visited, false, sizeof(visited));
        return solve(0, 0, grid);
    }
};


// METHOD 2: DIJKSTRA METHOD

class Solution {
  public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> dist(n+1, vector<int> (n+1, INT_MAX));
        dist[0][0] = grid[0][0];
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int w = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;
            
            for(auto &d : directions){
                int x = i + d[0];
                int y = j + d[1];
                
                if(x < n && x >= 0 && y < n && y >= 0){
                    int w2 = grid[x][y];
                    if(dist[x][y] > w + w2){
                        dist[x][y] = w + w2;
                        pq.push({w+w2, {x, y}});
                    }
                }
            }
        }
        
        return dist[n-1][n-1];
    }
};
