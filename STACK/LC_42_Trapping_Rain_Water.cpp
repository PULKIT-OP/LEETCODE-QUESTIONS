// Question Link: https://leetcode.com/problems/trapping-rain-water/description/

// METHOD 1: BruteForce Method --> TLE

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWaterLog = 0;
        for(int i = 0; i < n; i++){
            // left
            int left = 0;
            for(int l = i-1; l >= 0; l--){
                if(height[l] > height[i]){
                    left = max(height[l], left);
                }
            }
            if(left == 0){
                continue;
            }
            // right
            int right = 0;
            for(int r = i+1; r < n; r++){
                if(height[r] > height[i]){
                    right = max(height[r], right);
                }
            }
            if(right == 0){
                continue;
            }
            totalWaterLog += min(left-height[i], right-height[i]);
        }
        return totalWaterLog;
    }
};


// METHOD 2: Logic as same as aboe but its optimized a bit, earlier for each index i was finding left greatest and right greatest, but in this method i calculated it before hand
// But here we are consuming extra space to store left and right greatest for each node
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> preMax(n, 0);
        preMax[0] = height[0];
        vector<int> postMax(n, 0);
        postMax[n-1] = height[n-1];

        for(int i = 1; i < n; i++){
            preMax[i] = max(preMax[i-1], height[i]);
        }
        for(int i = n-2; i >= 0; i--){
            postMax[i] = max(postMax[i+1], height[i]);
        }

        int totalWaterLog = 0;
        for(int i = 0; i < n; i++){
            int left = (i>0) ? preMax[i-1] : 0;
            int right = (i<n-1) ? postMax[i+1] : 0;

            int water = min(left, right) - height[i];
            totalWaterLog += (water > 0) ? water : 0;
        }
        
        return totalWaterLog;
    }
};


// METHOD 3: More optimized

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int left = 0;
        int right = n-1;
        int total = 0;
        int left_max = 0;
        int right_max = 0;
        while(left < right){
            if(height[left] <= height[right]){
                // someone is there in left
                if(left_max > height[left]){
                    total += (left_max - height[left]);
                }
                else{
                    left_max = height[left];
                }
                left++;
            }
            else{
                // someone is there in right
                if(right_max > height[right]){
                    total += (right_max - height[right]);
                }
                else{
                    right_max = height[right];
                }
                right--;
            }
        }

        return total;
    }
};
