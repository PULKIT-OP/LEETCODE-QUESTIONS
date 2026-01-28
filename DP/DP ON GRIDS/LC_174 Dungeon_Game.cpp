// Question Link: https://leetcode.com/problems/dungeon-game/description/


// METHOD 1: BINARY SEARCH + RECURSION   ---->  TLE confirmed

class Solution {
public:
    int m;
    int n;
    bool canReach(int i, int j, int health, vector<vector<int>>& grid){
        if(i >= m || j >= n){
            return false;
        }

        health = health + grid[i][j];
        if(health <= 0){
            return false;
        }

        if(i == m-1 && j == n-1){
            return true;
        }

        return canReach(i+1, j, health, grid) || canReach(i, j+1, health, grid);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        int l = 1;
        int r = 4 * 1e7;
        int ans = 4 * 1e7;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(canReach(0, 0, mid, dungeon)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};


// METHOD 2: BINARY SEARCH + RECURSION + MEMOIZATION    ---->   STILL TLE 

class Solution {
public:
    int m;
    int n;
    unordered_map<string, int> mp;
    bool canReach(int i, int j, int health, vector<vector<int>>& grid){
        if(i >= m || j >= n){
            return false;
        }

        health = health + grid[i][j];
        if(health <= 0){
            return false;
        }

        if(i == m-1 && j == n-1){
            return true;
        }

        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(health);
        if(mp.count(key)){
            return mp[key];
        }

        return mp[key] = canReach(i+1, j, health, grid) || canReach(i, j+1, health, grid);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        int l = 1;
        int r = 4 * 1e7;
        int ans = 4 * 1e7;
        while(l <= r){
            int mid = l + (r-l)/2;
            mp.clear();
            if(canReach(0, 0, mid, dungeon)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};



// METHOD 3: RECURSION ---> DP

class Solution {
public:
    int m; int n;
    int solve(int i, int j, vector<vector<int>>& grid){
        // if out of bound then you cant reach out of bound so return infinity health
        if(i >= m || j >= n){
            return INT_MAX;
        }
        // if you reached last cell then check if it has value greater then zero if yes means it is not reducing any health ---> so if you come with minimum health(i.e 1) it will work. so return minimum value which is 1
        if(i == m-1 && j == n-1){
            if(grid[i][j] > 0){
                return 1;
            }
        // otherwise, if you have value in last cell which is smaller than 0, then you need atleast 1 more health than absolute value of that cell
        // are bhai desi language me samjh: agar to last cell ki value positive hai it menas koi reduction nahi ho raha health me to agar tu h 1 hp leke bhi aaega to koi dikkt nahi hai tu zero pe nahi pahuchega
        // but but but last cell ki value negative ho jati hai to utni value teri hp me se kam ho jaegi ---> to tujhe atleast usse 1 hp jyada to rakhni padegi na jisse tu zinda reh paye bcoz 0 hp means death
        // abhi bhi nahi samjha to pen paper se krke dekh ----> tab bhi nahi samjha to DSA chod de
            else{
                return abs(grid[i][j]) + 1;
            }
        }

        // or yadi tum last cell pr nahi ho to, right and down se check karo konsa path thik hai
        int right = solve(i, j+1, grid);
        int down = solve(i+1, j, grid);

        // right or down se jo bhi minimum value aayi hai usme se current cell ki value subtract krdo ---> nahi nahi galat mt samjho ---> current cell me do value ho sakti hai positive ya to negative 
        // agar negative hai to jo bhi value minimum value aayi right-down se to minus to krna hi padega. and agar current cell me positive value hai to minus krke ye pata lag jaega ki current cell me koi large value to nahi hai agar hai to final value -ve aaegi minus krke or agar -ve value aa gayi to tumhe sirf 1 health lekr aana hai iss cell me bahi health yaha se mil jaegi 
        int result = min(right, down) - grid[i][j];

        // agar minus krke result positive aata hai to result return kr do --> means jitni zarurt hai utna hi hai health
        // agar minus krke result negative aata hai to 1 return kr do ---> menas health ki utni zarurt nahi hai 1 hp se bhi kaam chal jaega
        return (result > 0) ? result : 1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        return solve(0, 0, dungeon);
    }
};


// METHOD 4: RECURSION + MEMOIZATION

class Solution {
public:
    int m; int n;
    int dp[201][201];
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i >= m || j >= n){
            return INT_MAX;
        }
        if(i == m-1 && j == n-1){
            if(grid[i][j] > 0){
                return 1;
            }
            else{
                return abs(grid[i][j]) + 1;
            }
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solve(i, j+1, grid);
        int down = solve(i+1, j, grid);

        int result = min(right, down) - grid[i][j];

        return dp[i][j] = (result > 0) ? result : 1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, dungeon);
    }
};


// METHOD 5: BOTTOM UP 
// STATE DEFINITION : dp[i][j] = minimum health requirec to reach cell [m-1][n-1] from cell [i][j] 
// Same logic as recursion no change

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1){
                    if(dungeon[i][j] >= 0){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = abs(dungeon[i][j]) + 1;
                    }
                }
                else{
                    int down = (i+1) >= m ? 1e9 : dp[i+1][j];
                    int right = (j+1) >= n ? 1e9 : dp[i][j+1];

                    int result = min(right, down) - dungeon[i][j];
                    dp[i][j] = (result > 0) ? result : 1;
                }
            }
        }

        return dp[0][0];
    }
};
