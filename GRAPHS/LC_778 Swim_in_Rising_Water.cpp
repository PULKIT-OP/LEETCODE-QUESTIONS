// Question Link: https://leetcode.com/problems/swim-in-rising-water/

// METHOD 1: Using DFS + Binary Search
// Logic behind this method is simple we will initially assume the highest possible time that we might take, and that is total no. of cell
// then gradually decrease time using binary search if possible and reach to final answer.
// basic template is of binary serach with while loop and mid, you will check if mid(time) is possible to reach bottom right from (0, 0)? 
// If yes then your answer will be mid for now and now make your 'r' as 'mid - 1' for further calculations
// If no then make your l as 'mid + 1' for further calculations
// How we gonna check if its possible or not?
// first check if your i and j are in bound and and and your cell at (i, j) is not exceeding the level of water which your current cell had and over that if your (i, j) is not already visited in this calculation
// If you failed any case mentined above then this time(mid) is not possible find another time to reach (n, n)
// If you passed all the cases first mark it viisted first
// then check if its the last cell? if yes return true means you reached if no then
// find its neighbour and check if thats possible -- > if yes then return yes otherwise return false

class Solution {
public:
    int n;
// Direction vector to traverse through all four directions
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// visited array to keep track of which node is visited;
    bool visited[50][50];

    bool isPossible(int u, int i, int j, vector<vector<int>>& grid) {
      // if i and j are invalid or cell is higher or the cell is already visited in this iteration return false as this path is not possible
        if (i >= n || i < 0 || j >= n || j < 0 || grid[i][j] > u ||
            visited[i][j]) {
            return false;
        }
      // if all condition are invalid for this cell then mark it true
        visited[i][j] = true;

      // Now check if this is your last cell as we have to travel till last cell ---> if YES then return true
        if (i == n - 1 && j == n - 1) {
            return true;
        }

      // Now check all four directions
        for (auto& e : direction) {
            int new_i = i + e[0];
            int new_j = j + e[1];
          // if possible then return true
            if (isPossible(u, new_i, new_j, grid)) {
                return true;
            }
        }
      // return false at last is no true is returned  ---> it means there is no path possible 
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
      // always start from the starting cell 
        int l = grid[0][0];
      // Taking the highest possible cell (worst case)
        int r = n * n - 1;


      // To store result 
        int result = 0;
        while (l <= r) {
          // for each iteration reset your visited array as new path will be tracked
            memset(visited, 0, sizeof(visited));
            int mid = l + (r - l)/2;
          // if this path is possible then update result 
            if (isPossible(mid, 0, 0, grid)) {
              // update result as mid 
                result = mid;
              // now check for a smaller answer so shrink your r
                r = mid - 1;
            } else {
              // is current path is not possible then move your left pointer 
                l = mid + 1;
            }
        }
        // at last return your final answer
        return result;
    }
};


// METHOD 2: Using Dijkstra's Algo with little change

class Solution {
public:
    int n;
    bool visited[50][50];
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        auto isValid = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < n;
        };

        while(!pq.empty()){
            auto temp = pq.top();
            int w = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;
            pq.pop();
            if(i == n-1 && j == n-1){
                return w;
            }
            for(int d = 0; d < 4; d++){
                int x = i + directions[d][0];
                int y = j + directions[d][1];
                if(isValid(x, y) && !visited[x][y]){
                    int new_w = grid[x][y];
                    pq.push({max(w, new_w), {x, y}});
                    visited[x][y] = true;
                }
            }   
        }

        return -1;
    }
};
