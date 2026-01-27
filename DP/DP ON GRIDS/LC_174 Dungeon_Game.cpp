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
