// Question Link: https://leetcode.com/problems/01-matrix/


// USING BFS ---> As shortest path is asked 
// We will call BFS from each zero to cell to the nearest 1 cell
// Maintain a size array and initialize it with -1 and put zero at all the cell where zero is present
// for each cell which have zero hit bfs check all the neighbour and if you get any closest 1 update its size then push in que


class Solution {
public:
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> que;
        vector<vector<int>> sizeMat(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
              // pushing cordinates of zero in que and updating size array for zero
                if(mat[i][j] == 0){
                    que.push({i, j});
                    sizeMat[i][j] = 0;
                }
            }
        }
        while(!que.empty()){
            int size = que.size();

            while(size--){
                int x = que.front().first;
                int y = que.front().second;
                que.pop();

              // iterating over neighbours
                for(auto &e : direction){
                    int new_x = x + e.first;
                    int new_y = y + e.second;
                  // if you get any neighbour which is -1 it means it is having one so update its size and push in que
                    if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && sizeMat[new_x][new_y] == -1){
                        sizeMat[new_x][new_y] = sizeMat[x][y] + 1;
                        que.push({new_x, new_y});
                    }
                }
            }
        }

        return sizeMat;
    }
};
};
