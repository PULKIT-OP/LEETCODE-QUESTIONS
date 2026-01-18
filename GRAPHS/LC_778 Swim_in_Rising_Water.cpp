// Question Link: https://leetcode.com/problems/swim-in-rising-water/

// METHOD 1: Using DFS + Binary Search

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
