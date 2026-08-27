// Question Link: https://leetcode.com/problems/combination-sum/description/


// METHOD 1: Using BackTracking

class Solution {
public:
    int n;
    void solve(int idx, vector<int> &nums, int target, set<vector<int>> &result, vector<int> &curr){
        if(idx == n){
            if(target == 0){
                result.insert(curr);
            }
            return;
        }
        if(target == 0){
            result.insert(curr);
        }
        curr.push_back(nums[idx]);
        if(target - nums[idx] >= 0){
            solve(idx, nums, target-nums[idx], result, curr);
        }
        curr.pop_back();
        solve(idx+1, nums, target, result, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        set<vector<int>> result;
        vector<int> curr;
        solve(0, candidates, target, result, curr);

        vector<vector<int>> ans(result.begin(), result.end());
        return ans;
    }
};

// METHOD 2: same thing just using vectors --> because i thought there would be duplicates while doing previous method, but now i realized that we have distinct elements 

class Solution {
public:
    int n;
    void solve(int idx, vector<int> &nums, int target, vector<vector<int>> &result, vector<int> &curr){
        if(idx == n){
            if(target == 0){
                result.push_back(curr);
            }
            return;
        }
        if(target == 0){
            result.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        if(target - nums[idx] >= 0){
            solve(idx, nums, target-nums[idx], result, curr);
        }
        curr.pop_back();
        solve(idx+1, nums, target, result, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<vector<int>> result;
        vector<int> curr;
        solve(0, candidates, target, result, curr);
        return result;
    }
};

