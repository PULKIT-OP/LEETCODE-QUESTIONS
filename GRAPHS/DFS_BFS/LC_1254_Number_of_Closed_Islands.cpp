// Question Link: https://leetcode.com/problems/number-of-closed-islands/description



// METHOD 1: Using DFS --> Kindof BruteForce

class Solution {
public:
    int m, n; 
    bool boundary = false;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void DFS(int i, int j, vector<vector<bool>> &visited, vector<vector<int>>& grid){
        visited[i][j] = true;

        if(i == 0 || j == 0 || i == m-1 || j == n-1){
            boundary = true;
        }

        for(auto d : directions){
            int x = i + d[0];
            int y = j + d[1];

            if(x < m && y < n && x >= 0 && y >= 0 && visited[x][y] == false && grid[x][y] == 0){
                DFS(x, y, visited, grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for(int i = 1; i < m-1; i++){
            for(int j = 1; j < n-1; j++){
                if(grid[i][j] == 0 && i < m-1 && j < n-1 && i > 0 && j > 0){
                    if(!visited[i][j]){
                        boundary = false;
                        DFS(i, j, visited, grid);
                        if(boundary == false){
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
};


// METHOD 2: Weithout using visited array

class Solution {
public:
    int m, n; 
    bool boundary = false;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void DFS(int i, int j, vector<vector<int>>& grid){
        grid[i][j] = 1;

        if(i == 0 || j == 0 || i == m-1 || j == n-1){
            boundary = true;
        }

        for(auto d : directions){
            int x = i + d[0];
            int y = j + d[1];

            if(x < m && y < n && x >= 0 && y >= 0 && grid[x][y] == 0){
                DFS(x, y, grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;
        for(int i = 1; i < m-1; i++){
            for(int j = 1; j < n-1; j++){
                if(grid[i][j] == 0 && i < m-1 && j < n-1 && i > 0 && j > 0){
                    boundary = false;
                    DFS(i, j, grid);
                    if(boundary == false){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};


// METHOD 3: More optimized with the same logic but diff method 

class Solution {
public:
    int m, n; 
    bool DFS(int i, int j, vector<vector<int>>& grid){
        if(i >= m || j >= n || i < 0 || j < 0){
            return false;
        }
        if(grid[i][j] == 1){
            return true;
        }

        grid[i][j] = 1;

        bool left = DFS(i, j-1, grid);
        bool right = DFS(i, j+1, grid);
        bool up = DFS(i-1, j, grid);
        bool down = DFS(i+1, j, grid);

        return left && right && up && down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;
        for(int i = 1; i < m-1; i++){
            for(int j = 1; j < n-1; j++){
                if(grid[i][j] == 0){
                    if(DFS(i, j, grid)){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
