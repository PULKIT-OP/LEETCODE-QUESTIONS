// Question Link: https://leetcode.com/problems/course-schedule/description/

// METHOD 1: Using Kahn's Algorithm(BFS) ----> if cycle exist then cant complete all courses means return false, and if it is acyclic then return true.

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
      // making adj list
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < n; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
        }

        queue<int> que;
        vector<int> inDeg(numCourses, 0);    // inDegree storage
        int count = 0;
      
      // allocating inDegrees
        for(int i = 0; i < n; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            inDeg[u]++;
        }
      // filling up que initially for those nodes which have zero inDegree
        for(int i = 0; i < numCourses; i++){
            if(inDeg[i] == 0){
                que.push(i);
            }
        }
      // Normal BFS algorithm
        while(!que.empty()){
            int node = que.front();
            que.pop();
            count++;

            for(auto &v : adj[node]){
                inDeg[v]--;

                if(inDeg[v] == 0){
                    que.push(v);
                }
            }
        }
      //if counted nodes != given nodes means cycle exist so return false
        if(count != numCourses){
            return false;
        }

        return true;

    }
};


// METHOD 2: TOPOLOGICAL SORT USING DFS
