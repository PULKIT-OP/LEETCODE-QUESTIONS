// Question Link: https://leetcode.com/problems/sliding-window-maximum/description/

// METHOD 1: Using Doubly ended queue ---> O(n)
// It involves only four step process
// STEP 1: when new element comes, make space for new element ---> keep only k elements in deck
// STEP 2: Now when new element comes, there is no need to keep smaller elments in the deck --> remove them
// STEP 3: Now push the new idx in deck
// STEP 4: If (i >= k-1) then front element of deck is our answer

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> result;

        for(int i = 0; i < n; i++){
            // step 1: check if space Available
            while(!q.empty() && q.front() <= i - k){
                q.pop_front();
            }

            // step 2
            while(!q.empty() && nums[i] > nums[q.back()]){
                q.pop_back();
            }

            // step 3
            q.push_back(i);

            // step 4
            if(i >= k-1){
                result.push_back(nums[q.front()]);
            }
        }

        return result;
    }
};
