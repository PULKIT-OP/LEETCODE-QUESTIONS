// Question Link: https://leetcode.com/problems/shift-2d-grid/description/


// METHOD 1: Trying to convert it into 1D Array then solve it then again convert into 2D array ---> HAPPY HAPPY

class Solution {
public:
    int m, n;
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        if(m == 1 && n == 1){
            return grid;
        }

        k = k%(m*n);

        vector<int> temp;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                temp.push_back(grid[i][j]);
            }
        }

        reverse(temp.begin(), temp.end());
        reverse(temp.begin(), temp.begin()+k);
        reverse(temp.begin()+k, temp.end());

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                grid[i][j] = temp.back();
                temp.pop_back();
            }
        }

        return grid;
    }
};
