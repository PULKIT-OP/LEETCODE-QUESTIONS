// Question Link: https://leetcode.com/problems/find-eventual-safe-states/description/


// METHOD 1: 
// Anyone who is part of Cycle ----> Cannot be a SAFE node
// And anyone who is leading to Cycle ---> Cannot be a SAFE node

class Solution {
public:
  // normal dfs code for checking cycle with some tweaks
    bool isCycleDFS(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inRecursion, vector<bool> &checkSafe){
        visited[u] = true;
        inRecursion[u] = true;
        
        for(auto &v : adj[u]){
            if(!visited[v] && isCycleDFS(v, adj, visited, inRecursion, checkSafe)){
                checkSafe[v] = false;
                return true;
            }
            else if(visited[v] == true && inRecursion[v] == true){
                checkSafe[v] = false;
                return true;
            }
        }
        checkSafe[u] = true;  // if code executes successfully then mark it as safe node --> because if for a particular node it didnot return true in middle that means cycle is not present and its a safe node
        inRecursion[u] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
      
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);
        vector<bool> checkSafe(n, false);  // To mark a node if it is a safe node
        vector<int> result; // to store all the safe nodes
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                isCycleDFS(i, graph, visited, inRecursion, checkSafe);
            }
        }
        // storing safe nodes and return at last
        for(int i = 0; i < n; i++){
            if(checkSafe[i] == true){
                result.push_back(i);
            }
        }

        return result;
    }
};

// METHOD 2: Using TOPOLOGICAL SORT LOGIC(BFS --> KAHN's Algorithm)
// Initially we reversed the edges
// then did normal topological sort and the answer we got we reversed it and returned it

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> inDeg(n, 0);
        for(int i = 0; i < n; i++){
            vector<int> temp = graph[i];
            for(int j = 0; j < temp.size(); j++){
                adj[temp[j]].push_back(i);
                inDeg[i]++;
            }
        }

        vector<int> result;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);

            for(auto &it : adj[node]){
                inDeg[it]--;

                if(inDeg[it] == 0){
                    q.push(it);
                }
            }
        }

        sort(result.begin(), result.end());

        return result;
    }
};

