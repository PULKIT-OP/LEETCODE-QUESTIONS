// Question Link: https://leetcode.com/problems/walking-robot-simulation/description/

// Method 1: using direction logic

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> consist;
        int n = commands.size();
        int o = obstacles.size();
        int x = 0;
        int y = 0;
        long long maxi = INT_MIN;

        pair<int, int> dir = {0, 1}; // north

        for(auto &e : obstacles){
            pair<int, int> p;
            p.first = e[0];
            p.second = e[1];
            consist.insert({p.first, p.second});
        }

        for(int i = 0; i < n; i++){
            if(commands[i] != -1 && commands[i] != -2){
                for(int j = 1; j <= commands[i]; j++){
                    if(consist.count({x+dir.first, y+dir.second})){
                        break;
                    }
                    x = x + dir.first;
                    y = y + dir.second;
                }
            }
            else if(commands[i] == -1){
                dir = {dir.second, -dir.first};
            }
            else if(commands[i] == -2){
                dir = {-dir.second, dir.first};
            }

            long long x_ = x*x;
            long long y_ = y*y;
            maxi = max(maxi, x_ + y_);
        }

        return maxi;
    }
};
