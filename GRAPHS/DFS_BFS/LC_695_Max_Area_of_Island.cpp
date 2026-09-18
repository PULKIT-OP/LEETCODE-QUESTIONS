// Question Link: https://leetcode.com/problems/max-area-of-island/description/

// METHOD 1: Using DFS, Not much optimized but doable

class Solution {
public:
    int m;
    int n;
    int maxArea = 0;
    int area = 0;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void DFS(int x, int y, vector<vector<bool>> &visited, vector<vector<int>>& grid){
        visited[x][y] = true;
        area++;

        for(auto &d : directions){
            int i = x + d[0];
            int j = y + d[1];

            if(i < m && i >= 0 && j < n && j >= 0 && grid[i][j] == 1){
                if(!visited[i][j]){
                    DFS(i, j, visited, grid);
                }
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == false && grid[i][j] == 1){
                    area = 0;
                    DFS(i, j, visited, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};


// METHOD 2: Little space optimization ---> made land to water [converted 1(land) to 0(water)]  ---> so no visited needed
// Use this method ONLY and ONLY if input mutation is allowed 

class Solution {
public:
    int m;
    int n;
    int maxArea = 0;
    int area = 0;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void DFS(int x, int y, vector<vector<int>>& grid){
        grid[x][y] = 0;
        area++;

        for(auto &d : directions){
            int i = x + d[0];
            int j = y + d[1];

            if(i < m && i >= 0 && j < n && j >= 0 && grid[i][j] == 1){
                DFS(i, j, grid);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    area = 0;
                    DFS(i, j, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};

