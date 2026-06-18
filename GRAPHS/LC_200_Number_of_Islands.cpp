// Question Link: https://leetcode.com/problems/number-of-islands/description/


// METHOD 1: Using DFS

class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;
    void DFS(vector<vector<char>>& grid, int i, int j, vector<vector<bool>> &visited){
        if(visited[i][j]){
            return;
        }
        visited[i][j] = true;

        for(auto &d : directions){
            int x_ = i + d[0];
            int y_ = j + d[1];

            if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid[x_][y_] == '1'){
                DFS(grid, x_, y_, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n, false));

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    DFS(grid, i, j, visited);
                    ans++;
                }
            }
        }

        return ans;
    }
};


// METHOD 2: USING BFS

class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;
    void BFS(vector<vector<char>>& grid, int i, int j, vector<vector<bool>> &visited){
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto &d : directions){
                int x_ = x + d[0];
                int y_ = y + d[1];

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid[x_][y_] == '1'){
                    if(!visited[x_][y_]){
                        q.push({x_, y_});
                        visited[x_][y_] = true;
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n, false));

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    BFS(grid, i, j, visited);
                    ans++;
                }
            }
        }

        return ans;
    }
};
