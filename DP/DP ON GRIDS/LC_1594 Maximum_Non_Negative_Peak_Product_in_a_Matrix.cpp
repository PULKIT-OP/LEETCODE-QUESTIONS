// Question Link: https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/

// METHOD 1: RECURSION ---> TLE aaega LAADLE

class Solution {
public:
    int m; int n;
    int MOD = 1e9 + 7;
    typedef long long ll;
    pair<ll, ll> solve(vector<vector<int>> &grid, int i, int j){
      // If you are on last cell then you can give only one value so return same value 
        if(i == m-1 && j == n-1){
            return {grid[i][j], grid[i][j]};
        }

      // To store maximum Value and minimum value 
        long long maxVal = LLONG_MIN;
        long long minVal = LLONG_MAX;

        // Exploring Down side of the cell if exist
        if(i+1 < m){
            auto [downMax, downMin] = solve(grid, i+1, j);
          // maximum value will be compared with current cell value PRODUCT with down side min value and max value, because we need final ans as product of the values
            maxVal = max({maxVal, (grid[i][j]*downMax), (grid[i][j]*downMin)});
          // minimum value will be compared with current cell value PRODUCT with down side min value and max value, because we need final ans as product of the values
            minVal = min({minVal, (grid[i][j]*downMax), (grid[i][j]*downMin)});
        }

        // Exploring Right side of the cell if exist
        if(j+1 < n){
            auto [rightMax, rightMin] = solve(grid, i, j+1);
          // maximum value will be compared with current cell value PRODUCT with right side min value and max value, because we need final ans as product of the values
            maxVal = max({maxVal, (grid[i][j]*rightMax), (grid[i][j]*rightMin)});
          // minimum value will be compared with current cell value PRODUCT with right side min value and max value, because we need final ans as product of the values
            minVal = min({minVal, (grid[i][j]*rightMax), (grid[i][j]*rightMin)});
        }

        return {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        pair<ll, ll> p = solve(grid, 0, 0);
        if(p.first < 0){
            return -1;
        }

        return p.first%MOD;
    }
};

// METHOD 2: MEMOIZATION

class Solution {
public:
    int m; int n;
    int MOD = 1e9 + 7;
    typedef long long ll;
    vector<vector<pair<ll, ll>>> dp;
    pair<ll, ll> solve(vector<vector<int>> &grid, int i, int j){
        if(i == m-1 && j == n-1){
            return {grid[i][j], grid[i][j]};
        }

        if(dp[i][j].first != LLONG_MIN && dp[i][j].second != LLONG_MAX){
            return dp[i][j];
        }

        long long maxVal = LLONG_MIN;
        long long minVal = LLONG_MAX;

        // Down
        if(i+1 < m){
            auto [downMax, downMin] = solve(grid, i+1, j);
            maxVal = max({maxVal, (grid[i][j]*downMax), (grid[i][j]*downMin)});
            minVal = min({minVal, (grid[i][j]*downMax), (grid[i][j]*downMin)});
        }

        // Right
        if(j+1 < n){
            auto [rightMax, rightMin] = solve(grid, i, j+1);
            maxVal = max({maxVal, (grid[i][j]*rightMax), (grid[i][j]*rightMin)});
            minVal = min({minVal, (grid[i][j]*rightMax), (grid[i][j]*rightMin)});
        }

        return dp[i][j] = {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp = vector<vector<pair<ll, ll>>>(m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));

        pair<ll, ll> p = solve(grid, 0, 0);
        if(p.first < 0){
            return -1;
        }

        return p.first%MOD;
    }
};

// METHOD 3: BOTTOM UP 

class Solution {
public:
    int MOD = 1e9 + 7;
    typedef long long ll;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<ll, ll>>> dp(m, vector<pair<ll, ll>>(n));
        dp[0][0].first = grid[0][0];
        dp[0][0].second = grid[0][0];

        for(int i = 1; i < m; i++){
            dp[i][0].first = dp[i-1][0].first*grid[i][0];
            dp[i][0].second = dp[i-1][0].second*grid[i][0];
        }
        for(int j = 1; j < n; j++){
            dp[0][j].first = dp[0][j-1].first*grid[0][j];
            dp[0][j].second = dp[0][j-1].second*grid[0][j];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j].first = max({dp[i-1][j].first*grid[i][j], dp[i-1][j].second*grid[i][j], dp[i][j-1].first*grid[i][j],dp[i][j-1].second*grid[i][j]});
                dp[i][j].second = min({dp[i-1][j].first*grid[i][j], dp[i-1][j].second*grid[i][j], dp[i][j-1].first*grid[i][j],dp[i][j-1].second*grid[i][j]});
            }
        }

        if(dp[m-1][n-1].first < 0){
            return -1;
        }

        return dp[m-1][n-1].first%MOD;
    }
};
