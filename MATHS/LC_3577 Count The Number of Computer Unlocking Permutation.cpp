// Question Link: https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/description/

class Solution {
public:
    int MOD = 1e9 + 7;
    long long fact(int n){
        long long ans = 1;
        for(int i = 1; i <= n; i++){
            ans = (ans%MOD) * i;
        }
        return ans%MOD;
    }
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

        int ans = 0;

        for(int i = 1; i < n; i++){
            if(complexity[i] <= complexity[0]){
                return 0;
            }
            ans++;
        }

        return fact(ans);
        
    }
};
