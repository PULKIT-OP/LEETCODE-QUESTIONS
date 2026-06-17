// Question Link: https://leetcode.com/problems/surrounded-regions/description/

// METHOD 1: Using BFS
// Find out all the nodes at border which are marked character 'O'
// Store them in queue and mark them as 'S' so that they stay safe from X
// Now BFS if you find any 'O' just mark it as 'S' and push in queue
// At last mark all all the 'O' in board as 'X' and all the 'S' as 'O'

class Solution {
public:
    vector<vector<int>>directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

      // Finding border 'O' and pushing in queue and marking them 'S'
        queue<pair<int, int>> q;
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                q.push({0, j});
                board[0][j] = 'S';
            }
            if(board[m-1][j] == 'O'){
                q.push({m-1, j});
                board[m-1][j] = 'S';
            }
        }
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = 'S';
            }
            if(board[i][n-1] == 'O'){
                q.push({i, n-1});
                board[i][n-1] = 'S';
            }
        }

      // Now BFS
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto &d : directions){
                int x_ = x + d[0];
                int y_ = y + d[1];

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && board[x_][y_] == 'O'){
                    q.push({x_, y_});
                    board[x_][y_] = 'S';
                }
            }
        }

      // Now final traversal and marking all the 'O' as 'X' and all the 'S' as 'O'
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
