// Question Link: https://leetcode.com/problems/regions-cut-by-slashes/description/


// METHOD 1: Using DFS --> Its like "number of Islands" question

class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void DFS(int i, int j, int n, vector<vector<bool>> &visited, vector<vector<bool>> &temp){
        visited[i][j] = true;

        for(auto d : directions){
            int x = i + d[0];
            int y = j + d[1];
            if(x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && temp[x][y] == 0){
                DFS(x, y, n, visited, temp);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
      // first convert each cell into 3*3 matrix and remake the grid 
        int n = grid.size();
        int N = 3*n;
        vector<vector<bool>> temp(N, vector<bool> (N, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '/'){
                    temp[i*3][j*3+2] = 1;
                    temp[i*3+1][j*3+1] = 1;
                    temp[i*3+2][j*3] = 1;
                }
                else if(grid[i][j] == '\\'){
                    temp[i*3][j*3] = 1;
                    temp[i*3+1][j*3+1] = 1;
                    temp[i*3+2][j*3+2] = 1;
                }
            }
        }

      // Then write the same logic as "Number of Islands"
        int count = 0;
        vector<vector<bool>> visited(N, vector<bool> (N, false));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j] && temp[i][j] == 0){
                    DFS(i, j, N, visited, temp);
                    count++;
                }
            }
        }

        return count;
    }
};

// METHOD 2: this can be solved using DSU as well but i couldnt understand its logic so, I'll update it soon
