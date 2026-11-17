// Question Link: https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/description/

// In this question we just have to find out minimum total cost to make the k groups semipalindrone
// here we have a string, we have to divide the string into k groups.
// then each group will have some characters --> we just have to find out what cost each group require to beocome a semi palindrone
// if you got the d, which gonna divide the goups
// then each groups will have its character in a pattern of indexes  --->  1, 1+d, 1+2d, 1+3d... and next group --> 2, 2+d, 2+3d.... and so on


// METHOD 1: Recursion + Memoization

class Solution {
public:
    int n;
    vector<vector<int>> costMemo;
    vector<vector<int>> memo;
    int findCost(int st, int end, string &s){
        if(costMemo[st][end] != -1){
            return costMemo[st][end];
        }
        int sz = end - st + 1;
        int i = 0;
        int j = sz-1;
        int minCost = 1e9;
        for(int d = 1; d < sz; d++){
            if(sz%d != 0){
                continue;
            }
            int cost = 0;
            for(int grp = 0; grp < d; grp++){
                int l = st + grp;
                int r = l + (sz/d - 1)*d;

                while(l < r){
                    if(s[l] != s[r]){
                        cost++;
                    }
                    l += d;
                    r -= d;
                }
            }

            minCost = min(cost, minCost);
        }

        return costMemo[st][end] = minCost;
    }
    int solve(int st, int k, string &s){
        if(k == 0){
            return st == n ? 0 : 1e9;
        }
        if(st + (2*k) > n){
            return 1e9;
        }
        if(memo[st][k] != -1){
            return memo[st][k];
        }
        long long minCost = 1e9;
        for(int end = st+1; end < n; end++){
            long long cost = findCost(st, end, s);
            long long remainingCost = solve(end+1, k-1, s);
            if(remainingCost >= 1e9){
                continue;
            }
            minCost = min(minCost, cost+remainingCost);
        }

        return memo[st][k] = minCost;
    }
    int minimumChanges(string s, int k) {
        n = s.length();
        costMemo.resize(n+1, vector<int>(n+1, -1));
        memo.resize(n+1, vector<int>(k+1, -1));
        return solve(0, k, s);
    }
};
