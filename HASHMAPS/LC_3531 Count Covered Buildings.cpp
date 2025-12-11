// Question Link: 

// Method 1: Self made Method  ---> check for the lowest and highest limits of y for each x and lowest and highest limits of x for each y.
// Then check if each pair of [x, y] of building falls in that limit range if yes then count if no then continue.

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int N = buildings.size();

        int ans = 0;

        unordered_map<int, pair<int, int>> limits_of_y_in_x;
        unordered_map<int, pair<int, int>> limits_of_x_in_y;

        for (int i = 0; i < N; i++) {

            int x = buildings[i][0];
            int y = buildings[i][1];

            if (limits_of_y_in_x.find(x) == limits_of_y_in_x.end()) {
                limits_of_y_in_x[x] = {y, y};
            } else {
                limits_of_y_in_x[x].first =
                    min(limits_of_y_in_x[x].first, y);
                limits_of_y_in_x[x].second =
                    max(limits_of_y_in_x[x].second, y);
            }

            if (limits_of_x_in_y.find(y) == limits_of_x_in_y.end()) {
                limits_of_x_in_y[y] = {x, x};
            } else {
                limits_of_x_in_y[y].first =
                    min(limits_of_x_in_y[y].first, x);
                limits_of_x_in_y[y].second =
                    max(limits_of_x_in_y[y].second, x);
            }
        }

        for (int i = 0; i < N; i++) {
            int x = buildings[i][0];
            int y = buildings[i][1];

            if ((limits_of_y_in_x.find(x) == limits_of_y_in_x.end()) ||
                (limits_of_x_in_y.find(y) == limits_of_x_in_y.end())) {
                continue;
            } 
            else {
                if (limits_of_y_in_x[x].first < y &&
                    limits_of_y_in_x[x].second > y) {
                        if(limits_of_x_in_y[y].first < x &&
                    limits_of_x_in_y[y].second > x){
                        ans++;
                    }
                    else{
                        continue;
                    }
                }
                else{
                    continue;
                }
            }
        }

        return ans;
    }
};
