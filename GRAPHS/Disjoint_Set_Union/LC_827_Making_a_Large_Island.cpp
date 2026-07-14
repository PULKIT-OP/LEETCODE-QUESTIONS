// Question Link: https://leetcode.com/problems/making-a-large-island/description/

// METHOD 1: Using DSU

class Solution {
public:
    // Basic DSU TEMPLATE Union and Find Algorithm
    int find(int x, vector<int> &parent){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x], parent);
    }
    void Union(int x, int y, vector<int> &parent, vector<int> &size){
        int xp = find(x, parent);
        int yp = find(y, parent);

        if(xp == yp){
            return;
        }

        if(size[xp] >= size[yp]){
            parent[yp] = xp;
            size[xp] += size[yp];
        }
        else if(size[yp] > size[xp]){
            parent[xp] = yp;
            size[yp] += size[xp];
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> parent(n*n);
        vector<int> size(n*n, 1);

        for(int i = 0; i < n*n; i++){
            parent[i] = i;
        }

      // lambda function to validate indexes
        auto valid = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < n;
        };

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};  // to iterate over neighbours

      // Making the connected components if any present
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    for(int d = 0; d < 4; d++){
                        int x = i + directions[d][0];
                        int y = j + directions[d][1];
                        // neighbour index is valid and its 1 then move further
                        if(valid(x, y) && grid[x][y] == 1){
                            int currP = find(i*n+j, parent);
                            int neighP = find(x*n+y, parent);
                            // if current cell and neighbour are not connected the Union
                            if(currP != neighP){
                                Union(i*n+j, x*n+y, parent, size);
                            }
                        }
                    }
                }
            }
        }
      // After connections find out the largest island as of now
        int maxi = 0;
        for(int i = 0; i < n*n; i++){
            if(parent[i] == i){
                maxi = max(maxi, size[i]);
            }
        }

      // Now finding largest island after connecting zeros
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int count = 0;
                if(grid[i][j] == 0){
                    unordered_set<int> st;
                    for(int d = 0; d < 4; d++){
                        int x = i + directions[d][0];
                        int y = j + directions[d][1];

                        if(valid(x, y) && grid[x][y] == 1){
                            int neigh = x*n+y;
                            int neighP = find(neigh, parent);
                            st.insert(neighP);  // if this neighbour component is valid then store it so that no duplicates occur
                        }
                    }
                  // Now iterate over stored components and count its sizes and store them
                    for(auto &it : st){
                        count += size[it];
                    }
                }
                maxi = max(maxi, count+1);  // find out maximum island size
            }
        }

      // return the maximum island size
        return maxi;
    }
};
