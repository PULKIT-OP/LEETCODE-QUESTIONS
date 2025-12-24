class Solution {
  public:

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       // Making adj list
        vector<vector<int>> adj(V);
        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
        }

      // populating initially indegree vector
        
        vector<int> indeg(V, 0);
        for(auto &v : edges){
            indeg[v[1]]++;
        }
        
        queue<int> que;
        
        vector<int> ans;    // vector to store topological sorted array

      // checking if we have any node with 0 indegree if yes then push it in que and in ans vector
        for(int i = 0; i < V; i++){
            if(indeg[i] == 0){
                que.push(i);
                ans.push_back(i);
            }
        }

      // now normal bfs code with little change
        while(!que.empty()){
            int node = que.front();
            que.pop();

          // if we visit any node decrease its indegree
            for(auto &v : adj[node]){
                indeg[v]--;

              // if indegree becomes zero then push it in que then in ans vector
                if(indeg[v] == 0){
                    que.push(v);
                    ans.push_back(v);
                }
            }
        }

      // at last return ans vector which has correct topological sort order.
        return ans;
    }
};
