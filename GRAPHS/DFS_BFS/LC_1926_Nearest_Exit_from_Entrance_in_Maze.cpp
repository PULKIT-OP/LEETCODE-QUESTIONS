// Question Link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/


// METHOD 1: Using BFS ---> Not much optimized but doable eazy pizy


class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        visited[entrance[0]][entrance[1]] = true;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x = temp[0];
            int y = temp[1];
            int steps = temp[2];

          // checking if x and y is bounded and not equal to entrance
            if((x == 0 || x == m-1 || y == 0 || y == n-1) && (x != entrance[0] || y != entrance[1])){
                return steps;
            }

            for(auto &d : directions){
                int i = x + d[0];
                int j = y + d[1];

                if(i >= 0 && i < m && j >= 0 && j < n && maze[i][j] == '.'){
                    if(visited[i][j] == false){
                        q.push({i, j, steps+1});
                        visited[i][j] = true;
                    }
                }
            }
        }

        return -1;
    }
};


// METHOD 2: Same as above just little space optimization --> updating all visited cells as walls ---> so we dont cross from there again
// So no need of visited
// try this one only when input mutation is allowed

class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze[0].size();

        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x = temp[0];
            int y = temp[1];
            int steps = temp[2];

            if((x == 0 || x == m-1 || y == 0 || y == n-1) && (x != entrance[0] || y != entrance[1])){
                return steps;
            }

            for(auto &d : directions){
                int i = x + d[0];
                int j = y + d[1];

                if(i >= 0 && i < m && j >= 0 && j < n && maze[i][j] == '.'){
                    q.push({i, j, steps+1});
                    maze[i][j] = '+';
                }
            }
        }

        return -1;
    }
};

