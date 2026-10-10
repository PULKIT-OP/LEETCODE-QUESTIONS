// Question Link: https://leetcode.com/problems/minimum-sum-of-squared-difference/description/


// METHOD 1: Using Priority_Queue it was giving TLE


// METHOD 2: Using Normal arrays and frequency things

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        vector<int> difference(n);
        vector<int> freq(1e5+1, 0);
        long long total_diff_sum = 0;
        for(int i = 0; i < n; i++){
            difference[i] = abs(nums1[i] - nums2[i]);
            freq[difference[i]]++;
            total_diff_sum += difference[i];
        }

        int k = k1 + k2;

        if((long long)k >= total_diff_sum){
            return 0;
        }

        long long result = 0;
        for(int i = 1e5; i >= 1 && k > 0; i--){
            int node = i;
            int f = freq[node];
            int diffOps = min(f, k);

            f = f - diffOps;
            freq[node] = f;

            node--;
            freq[node] += diffOps;

            k = k - diffOps;
        }

        for(int i = 0; i < 1e5+1; i++){
            result += 1LL * i * i * freq[i];
        }

        return result;
    }
};
