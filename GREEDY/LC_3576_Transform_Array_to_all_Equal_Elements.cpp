// Question Link: https://leetcode.com/problems/transform-array-to-all-equal-elements/description/

// METHOD 1: Brute force method

class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        int steps = 0;
        bool case1 = true;
        bool case2 = true;
        vector<int> test = nums;

        // case 1 --> all +1
        for(int i = 0; i < n && i+1 < n; i++){
            if(test[i] == -1){
                test[i] = 1;
                test[i+1] = -test[i+1];
                steps++;
                if(steps == k){
                    break;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(test[i] == -1){
                case1 = false;
                break;
            }
        }

        if(case1){
            return true;
        }

        // case 2 --> all -1;
        test = nums;
        steps = 0;
        for(int i = 0; i < n && i+1 < n; i++){
            if(test[i] == 1){
                test[i] = -1;
                test[i+1] = -test[i+1];
                steps++;
                if(steps == k){
                    break;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(test[i] == 1){
                case2 = false;
                break;
            }
        }

        if(case2){
            return true;
        }

        return false;
    }
};
