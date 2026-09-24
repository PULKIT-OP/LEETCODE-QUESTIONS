// Question Link: https://leetcode.com/problems/time-needed-to-inform-all-employees/description/

// METHOD 1: Using BFS

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
      // Making adj list
      // manager vec is like emp -> manager
      // so adj list should be manager -> emp1, emp2, emp3....
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            int manag = manager[i];
            if(manag != -1){
                adj[manag].push_back(i);
            }
        }

      // Now normal BFS
        queue<pair<int, int>> q;
        int maxTime = INT_MIN; // to store max time needed to reach a employee
        q.push({headID, 0});
        while(!q.empty()){
            auto temp = q.front();
            int id = temp.first;
            int time = temp.second;
            q.pop();
            maxTime = max(maxTime, time);

            for(auto v : adj[id]){
                q.push({v, time + informTime[id]});
            }
        }

        return maxTime;
    }
};


// METHOD 2: Using DFS, same logic as above just diff algo

class Solution {
public:
    int maxtime = INT_MIN;
    void DFS(vector<vector<int>> &adj, int headID, int time, vector<int>& informTime){
        maxtime = max(maxtime, time);

        for(auto e : adj[headID]){
            DFS(adj, e, time + informTime[headID], informTime);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            int manag = manager[i];
            if(manag != -1){
                adj[manag].push_back(i);
            }
        }

        DFS(adj, headID, 0, informTime);

        return maxtime;
    }
};
