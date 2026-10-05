// Question Link: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/

// METHOD 1: Using Dijkstra's Algorithm
// Nothing To explain, simple logic and code

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> visited(m, vector<int> (n, -1));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0, 0, k});
        if(grid[0][0] == 1){
            k--;
        }
        visited[0][0] = k;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto temp = q.top();
                q.pop();
                int i = temp[1];
                int j = temp[2];
                int steps = temp[0];
                int kk = temp[3];

                if(i == m-1 && j == n-1){
                    return steps;
                }

                for(auto d : directions){
                    int x = i + d[0];
                    int y = j + d[1];

                    if(x >= 0 && x < m && y >= 0 && y < n){
                        int kkk = kk;
                        if(grid[x][y] == 1){
                            kkk--;
                        }
                        if(kkk < 0){
                            continue;
                        }
                        if(kkk > visited[x][y]){
                            q.push({steps+1, x, y, kkk});
                            visited[x][y] = kkk;
                        }
                    }
                }
            }
        }

        return -1;
    }
};

// METHOD 2: Using BFS

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> visited(m, vector<int> (n, -1));
        queue<vector<int>> q;
        q.push({0, 0, 0, k});
        if(grid[0][0] == 1){
            k--;
        }
        visited[0][0] = k;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto temp = q.front();
                q.pop();
                int i = temp[1];
                int j = temp[2];
                int steps = temp[0];
                int kk = temp[3];

                if(i == m-1 && j == n-1){
                    return steps;
                }

                for(auto d : directions){
                    int x = i + d[0];
                    int y = j + d[1];

                    if(x >= 0 && x < m && y >= 0 && y < n){
                        int kkk = kk;
                        if(grid[x][y] == 1){
                            kkk--;
                        }
                        if(kkk < 0){
                            continue;
                        }
                        if(kkk > visited[x][y]){
                            q.push({steps+1, x, y, kkk});
                            visited[x][y] = kkk;
                        }
                    }
                }
            }
        }

        return -1;
    }
};


// METHOD 3: Standard 3 states solution 

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<bool>>> visited(m, vector<vector<bool>> (n, vector<bool> (k+1, false)));
        queue<vector<int>> q;
        if(grid[0][0] == 1){
            k--;
        }
        q.push({0, 0, 0, k});
        visited[0][0][k] = true;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto temp = q.front();
                q.pop();
                int i = temp[1];
                int j = temp[2];
                int steps = temp[0];
                int kk = temp[3];

                if(i == m-1 && j == n-1){
                    return steps;
                }

                for(auto d : directions){
                    int x = i + d[0];
                    int y = j + d[1];

                    if(x >= 0 && x < m && y >= 0 && y < n){
                        int kkk = kk;
                        if(grid[x][y] == 1){
                            kkk--;
                        }
                        if(kkk < 0){
                            continue;
                        }
                        if(!visited[x][y][kkk]){
                            q.push({steps+1, x, y, kkk});
                            visited[x][y][kkk] = true;
                        }
                    }
                }
            }
        }

        return -1;
    }
};
