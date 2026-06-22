// Question Link: https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1


// METHOD 1: Using BFS
// After each multiplication check if you already used this number before if yes then do not traverse again the same number 
// If not seen this number then please iterate over this number may be you will find some good answer

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        vector<bool> visited(1001, false);  // To track the numbers if i have visited them
        visited[start] = true;
        
        queue<pair<int, int>> q;
        q.push({start, 0});
        
        int ans = INT_MAX;  // To store final minimum answer
        
        while(!q.empty()){
            auto temp = q.front();
            int node = temp.first;
            int count = temp.second;
            q.pop();
            
            if(node == end){  // if you found end then store the steps reaching it if it is smallest till now
                ans = min(ans, count);
            }
            
            for(auto &e : arr){
                int multi = node*e;
                multi = multi%1000;
                
                if(!visited[multi]){
                    q.push({multi, count+1});
                    visited[multi] = true;
                }
            }
        }
        
        
        if(ans != INT_MAX){
            return ans;
        }
        
        return -1;
    }
};
