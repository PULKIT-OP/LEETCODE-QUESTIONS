// Question Link: https://leetcode.com/problems/3sum/description/

// METHOD 1: BRUTE FORCE -->   TLE (311 / 316 testcases passed)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> result;
        set<vector<int>> st;
        for(int i = 0; i <= n-3; i++){
            for(int j = i+1; j <= n-2; j++){
                for(int k = j+1; k <= n-1; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);

                        sort(v.begin(), v.end());
                        if(st.find(v) == st.end()){
                            st.insert(v);
                            result.push_back(v);
                        }
                    }
                }
            }
        }

        return result;
    }
};

// METHOD 2: Optimized to O(n^2) ---> STILL TLE

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>> st;
        for(int i = 0; i < n; i++){
            set<int> mp;
            for(int j = i+1; j < n; j++){
                int third = -(nums[i] + nums[j]);
                if(mp.find(third) != mp.end()){
                    vector<int> v = {nums[i], nums[j], third};
                    sort(v.begin(), v.end());
                    st.insert(v);
                }
                mp.insert(nums[j]);
            }
        }

        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
};


// METHOD 3: More optimized ---> three pointers (actually two pointers logic)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
              // if sum is smaller then we have to increase the numbers ---> so increment the smaller numbers which are in starting
                if(sum < 0){
                    j++;
                }
              // if sum is greater than zero then we have to decrease the numbers ---> so decrease the greater numbers which are in ending of array
                else if(sum > 0){
                    k--;
                }
                else{
                  // otherwise we have found one triplet which sums up to zero push it in result
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    result.push_back(v);
                  // record the current values of jth index and kth index
                    int prev_k = nums[k];
                    int prev_j = nums[j];
                    j++;
                    k--;
                  // now increment j and k until they reaach some diffrent values then they have already counted
                    while(j < k && nums[j] == prev_j){
                        prev_j = nums[j];
                        j++;
                    }
                    while(j < k && nums[k] == prev_k){
                        prev_k = nums[k];
                        k--;
                    }
                }
            }
        }

        return result;
    }
};

