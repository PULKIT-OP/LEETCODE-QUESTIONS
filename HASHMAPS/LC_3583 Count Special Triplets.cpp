//Question link: https://leetcode.com/problems/count-special-triplets/description/

// Method 1: Using left Frequency hashmap and right Frequency hashmap.  TWO PASS SOLUTION

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int n = nums.size();
        long long ans = 0;

        unordered_map<long, long> left;
        unordered_map<long, long> right;

        for(int i = 0; i < n; i++){
            right[nums[i]]++;
        }

        for(int i = 0; i < n; i++){
            right[nums[i]]--;
            if(left[nums[i]*2] > 0 && right[nums[i]*2] > 0){
                ans += (right[nums[i] * 2] * left[nums[i] * 2]);
            }
            left[nums[i]]++;
        }
        return ans%MOD;    // as answer is long so taking MOD
    }
}; 


// Method 2: ONE PASS SOLUTION

// firstly check if the nums[i] is valid k or not if yes then we got our first triplet if not then check if it is valid j if yes then add it in valid_j map with its freq then at last fill up the valid_i map.

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int n = nums.size();
        long long ans = 0;

        unordered_map<long, long> valid_i;
        unordered_map<long, long> valid_j;

        for(int i = 0; i < n; i++){
            // valid k
            if(nums[i]%2 == 0){
                ans += valid_j[nums[i]/2];
            }

            // valid j
            if(valid_i[nums[i]*2] > 0){
                valid_j[nums[i]] += valid_i[nums[i]*2];
            }
          
            valid_i[nums[i]]++;
        }

        return ans%MOD;
    }
};
