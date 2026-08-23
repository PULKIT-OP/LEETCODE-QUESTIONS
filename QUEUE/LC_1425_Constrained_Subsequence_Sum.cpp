// Question Link: https://leetcode.com/problems/constrained-subsequence-sum/description/


// METHOD 1: Using Recursion ---> TLE

class Solution {
public:
    int n;
    int solve(vector<int> &nums, int i, int prev, int k){
        if(i >= n){
            return 0;
        }

        int take = 0;
        int not_take = 0;

        if(prev == -1){
            take = nums[i] + solve(nums, i+1, i, k);
            not_take = solve(nums, i+1, prev, k);
        }
        else{
            if(i - prev <= k){
                take = nums[i] + solve(nums, i+1, i, k);
            }
            not_take = solve(nums, i+1, prev, k);
        }

        return max(take, not_take);
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        n = nums.size();
        int ans = solve(nums, 0, -1, k);

        return ans > 0 ? ans : -1;
    }
};

// METHOD 2: Using Memoization  ---> MLE

class Solution {
public:
    int n;
    int solve(vector<int> &nums, int i, int prev, int k, vector<vector<int>> &dp){
        if(i >= n){
           return (prev == -1 ? INT_MIN : 0);
        }

        if(dp[i][prev+1] != INT_MIN){
            return dp[i][prev + 1];
        }

        int take = 0;
        int not_take = 0;

        if(prev == -1){
            take = nums[i] + solve(nums, i+1, i, k, dp);
            not_take = solve(nums, i+1, prev, k, dp);
        }
        else{
            if(i - prev <= k){
                take = nums[i] + solve(nums, i+1, i, k, dp);
            }
            not_take = solve(nums, i+1, prev, k, dp);
        }

        return dp[i][prev+1] = max(take, not_take);
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, INT_MIN));
        int ans = solve(nums, 0, -1, k, dp);

        return ans;
    }
};


// METHOD 3: BOTTOM UP ---> TLE

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> dp(n, 0);
        for(int i = 0; i<n; i++)
            dp[i] = nums[i];
        
        int maxR = dp[0];
        
        for(int i = 1; i<n; i++) {
            for(int j = i-1; i-j <= k && j >= 0; j--) {
                dp[i] = max(dp[i], nums[i] + dp[j]);
            }
            
            maxR = max(maxR, dp[i]);
        }
        
        
        return maxR;
    }
};

// METHOD 4: Using Priority Queue

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> dp(n, 0);
        for(int i = 0; i<n; i++)
            dp[i] = nums[i];
        
        int maxR = dp[0];

        priority_queue<pair<int, int>> pq;
        pq.push({dp[0], 0});
        
        for(int i = 1; i<n; i++) {
            while(!pq.empty() && pq.top().second < i - k){
                pq.pop();
            }
            if(!pq.empty()){
                dp[i] = max(dp[i], nums[i] + pq.top().first);
            }
            maxR = max(dp[i], maxR);
            pq.push({dp[i], i});
        }
        
        return maxR;
    }
};


// METHOD 5: Using Deqeue

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> dp(n);
        
        int maxR = nums[0];

        deque<int> dq;
        dq.push_back(0);
        
        for(int i = 0; i<n; i++) {
            while(!dq.empty() && dq.front() < i - k){
                dq.pop_front();
            }
            if(!dq.empty()){
                dp[i] = max(dp[i], nums[i] + dp[dq.front()]);
            }
            while(!dq.empty() && dp[dq.back()] <= dp[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            maxR = max(dp[i], maxR);
        }
        
        if(maxR <= 0){
            maxR = INT_MIN;
            for(int i = 0; i < n; i++){
                maxR = max(maxR, nums[i]);
            }
            return maxR;
        }

        return maxR;
    }
};

// revisit it later ---> still not clear 
