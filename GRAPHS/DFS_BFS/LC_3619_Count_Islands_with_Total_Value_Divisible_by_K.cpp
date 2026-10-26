// Question Link: https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/description/


// METHOD 1: Using Normal DFS Algorithm

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    long long DFS(int i, int j, vector<vector<int>>& grid){
        if(i >= m || j >= n || i < 0 || j < 0 || grid[i][j] == 0){
            return 0;
        }

        int sum = grid[i][j];
        grid[i][j] = 0;

        long long left = DFS(i, j-1, grid);
        long long right = DFS(i, j+1, grid);
        long long top = DFS(i-1, j, grid);
        long long bottom = DFS(i+1, j, grid);

        return (long long)(left + right + top + bottom + sum);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<long long> islandSum;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0){
                    long long sum = DFS(i, j, grid);
                    islandSum.push_back(sum);
                }
            }
        }

        int count = 0;
        for(auto e : islandSum){
            if(e%k == 0){
                count++;
            }
        }

        return count;
    }
};
