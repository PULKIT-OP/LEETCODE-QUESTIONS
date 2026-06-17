// Question Link: https://leetcode.com/problems/flood-fill/description/

// METHOD 1: Using BFS ---> Iterative 

class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      // If pixel color and provided color is same then just return 
      // If image[sr][sc] == color already then there can be two cases possible: 
      // case 1. adjacent pixels are of same color as image[sr][sc] so there is no need to change that so return directly
      // case 2. adjacent pixels are of different color then you cant move to them to change their color so then also return directly
        if(image[sr][sc] == color){
            return image;
        }
        int n = image.size(); // x
        int m = image[0].size(); // y

      // Now normal BFS nothing to explain now
        queue<pair<int, int>> q;
        q.push({sr, sc});
      
        int starting_color = image[sr][sc];
        image[sr][sc] = color;
      
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();

            int x = temp.first;
            int y = temp.second;

            for(int i = 0; i < 4; i++){
                int x_ = x + directions[i][0];
                int y_ = y + directions[i][1];

                if(x_ >= 0 && x_ < n && y_ >= 0 && y_ < m && image[x_][y_] == starting_color){
                    q.push({x_, y_});
                    image[x_][y_] = color;
                }
            }
        }

        return image;
    }
};
