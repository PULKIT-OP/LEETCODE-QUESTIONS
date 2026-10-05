// Question Link: https://leetcode.com/problems/shortest-path-to-get-all-keys/description/


// METHOD 1: Using set for visited 

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int shortestPathAllKeys(vector<string>& grid) {
        m = grid.size();
        n = grid[0].size();

        // . --> empty cell       # --> Wall        @ starting point

        int GlobalKeys = 0;
        set<vector<int>> seen;
        queue<vector<int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '@'){
                    q.push({i, j, 0});
                    seen.insert({i, j, 0});
                }
                else if(grid[i][j] >= 'a' && grid[i][j] <= 'z'){
                    GlobalKeys = GlobalKeys | (1 << (grid[i][j] - 'a'));
                }
            }
        }


        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto temp = q.front();
                q.pop();
                int i = temp[0];
                int j = temp[1];
                int keys = temp[2];

                if(keys == GlobalKeys){
                    return steps;
                }

                for(auto d : directions){
                    int x = i + d[0];
                    int y = j + d[1];
                    int keys2 = keys;
                    if(x >= m || x < 0 || y >= n || y < 0 || grid[x][y] == '#'){
                        continue;
                    }
                    if(grid[x][y] >= 'A' && grid[x][y] <= 'Z'){
                        int mask = 1 << (tolower(grid[x][y])-'a');
                        if((keys2 & mask) != 0 && seen.find({x,y,keys2}) == seen.end()){
                            q.push({x, y, keys2});
                            seen.insert({x, y, keys2});
                        }
                    }
                    else if(grid[x][y] >= 'a' && grid[x][y] <= 'z'){
                        int mask = 1 << (tolower(grid[x][y])-'a');
                        keys2 = keys2 | mask;
                        if(seen.find({x,y,keys2}) == seen.end()){
                            q.push({x, y, keys2});
                            seen.insert({x, y, keys2});
                        }
                    }
                    else if(seen.find({x, y, keys2}) == seen.end()){
                        q.push({x, y, keys2});
                        seen.insert({x, y, keys});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

// METHOD 2: using 3 states grid for visited

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int shortestPathAllKeys(vector<string>& grid) {
        m = grid.size();
        n = grid[0].size();

        // . --> empty cell       # --> Wall        @ starting point

        int GlobalKeys = 0;
        vector<vector<vector<bool>>> seen(m, vector<vector<bool>>(n, vector<bool>((1 << 6), false)));
        queue<vector<int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '@'){
                    q.push({i, j, 0});
                    seen[i][j][0] = true;
                }
                else if(grid[i][j] >= 'a' && grid[i][j] <= 'z'){
                    GlobalKeys = GlobalKeys | (1 << (grid[i][j] - 'a'));
                }
            }
        }


        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto temp = q.front();
                q.pop();
                int i = temp[0];
                int j = temp[1];
                int keys = temp[2];

                if(keys == GlobalKeys){
                    return steps;
                }

                for(auto d : directions){
                    int x = i + d[0];
                    int y = j + d[1];
                    int keys2 = keys;
                    if(x >= m || x < 0 || y >= n || y < 0 || grid[x][y] == '#'){
                        continue;
                    }
                    if(grid[x][y] >= 'A' && grid[x][y] <= 'Z'){
                        int mask = 1 << (tolower(grid[x][y])-'a');
                        if((keys2 & mask) != 0 && seen[x][y][keys2] == false){
                            q.push({x, y, keys2});
                            seen[x][y][keys2] = true;
                        }
                    }
                    else if(grid[x][y] >= 'a' && grid[x][y] <= 'z'){
                        int mask = 1 << ((grid[x][y])-'a');
                        keys2 = keys2 | mask;
                        if(seen[x][y][keys2] == false){
                            q.push({x, y, keys2});
                            seen[x][y][keys2] = true;
                        }
                    }
                    else if(seen[x][y][keys2] == false){
                        q.push({x, y, keys2});
                        seen[x][y][keys2] = true;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

// METHOD 3: Using queue<tuple<int, int, int>>  instead of queue<vector<int>> 

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int shortestPathAllKeys(vector<string>& grid) {
        m = grid.size();
        n = grid[0].size();

        // . --> empty cell       # --> Wall        @ starting point

        int GlobalKeys = 0;
        vector<vector<vector<bool>>> seen(m, vector<vector<bool>>(n, vector<bool>((1 << 6), false)));
        queue<tuple<int, int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '@'){
                    q.push({i, j, 0});
                    seen[i][j][0] = true;
                }
                else if(grid[i][j] >= 'a' && grid[i][j] <= 'z'){
                    GlobalKeys = GlobalKeys | (1 << (grid[i][j] - 'a'));
                }
            }
        }


        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [i, j, keys] = q.front();
                q.pop();

                if(keys == GlobalKeys){
                    return steps;
                }

                for(auto d : directions){
                    int x = i + d[0];
                    int y = j + d[1];
                    int keys2 = keys;
                    if(x >= m || x < 0 || y >= n || y < 0 || grid[x][y] == '#'){
                        continue;
                    }
                    if(grid[x][y] >= 'A' && grid[x][y] <= 'Z'){
                        int mask = 1 << ((grid[x][y])-'A');
                        if((keys2 & mask) != 0 && seen[x][y][keys2] == false){
                            q.push({x, y, keys2});
                            seen[x][y][keys2] = true;
                        }
                    }
                    else if(grid[x][y] >= 'a' && grid[x][y] <= 'z'){
                        int mask = 1 << ((grid[x][y])-'a');
                        keys2 = keys2 | mask;
                        if(seen[x][y][keys2] == false){
                            q.push({x, y, keys2});
                            seen[x][y][keys2] = true;
                        }
                    }
                    else if(seen[x][y][keys2] == false){
                        q.push({x, y, keys2});
                        seen[x][y][keys2] = true;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
