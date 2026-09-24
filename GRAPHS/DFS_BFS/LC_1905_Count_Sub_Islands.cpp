// Question Link: https://leetcode.com/problems/count-sub-islands/description/

// METHOD 1: Using DFS

class Solution {
public:
    int n;
    int m;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool DFS(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        grid2[i][j] = 0;

        bool partOfIsland = grid1[i][j];

        for(auto d : directions){
            int x = i + d[0];
            int y = j + d[1];
            if(x >= 0 && x < m && y >= 0 && y < n && grid2[x][y] == 1){
                if(!DFS(x, y, grid1, grid2)){
                    partOfIsland = false;
                }
            }
        }

        return partOfIsland;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j] == 1 && DFS(i, j, grid1, grid2)){
                    count++;
                }
            }
        }

        return count;
    }
};


// METHOD 2: Using BFS

class Solution {
public:
    int n;
    int m;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool BFS(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        bool partOfIsland = grid1[i][j];

        queue<pair<int, int>> q;
        grid2[i][j] = 0;
        q.push({i, j});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(grid1[x][y] != 1){
                partOfIsland = false;
            }

            for(auto d : directions){
                int x_ = x + d[0];
                int y_ = y + d[1];
                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid2[x_][y_] == 1){
                    grid2[x_][y_] = 0;
                    q.push({x_, y_});
                }
            }
        }

        return partOfIsland;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j] == 1 && BFS(i, j, grid1, grid2)){
                    count++;
                }
            }
        }

        return count;
    }
};
