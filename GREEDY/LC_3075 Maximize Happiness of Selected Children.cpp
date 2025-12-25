// Question Link: 

// METHOD 1: GREEDY APPROACH:    O(NlogN) time, O(1) space

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();

        long long result = 0;

        sort(happiness.begin(), happiness.end(), greater<int> ());

        for(int i = 0; i < k; i++){
            result += max(0, happiness[i] - i);
        }
        return result;
    }
};


// METHOD 2: MAX HEAP APPROACH:    O(NlogN) time, O(N) space

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();

        long long result = 0;

        priority_queue<int> pq;    // MAX HEAP
        for(int i = 0; i < n; i++){
            pq.push(happiness[i]);
        }
        
        for(int i = 0; i < k; i++){
            result += max(0, pq.top() - i);
            pq.pop();
        }
      
        return result;
    }
};
