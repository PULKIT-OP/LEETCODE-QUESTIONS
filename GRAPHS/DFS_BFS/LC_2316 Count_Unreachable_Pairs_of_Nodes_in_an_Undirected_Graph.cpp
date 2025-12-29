// Question Link: 

// METHOD 1: Using DFS

// using count to store the number of nodes in a provience or a connected group.
int count;
class Solution {
public:
    int count;
    void DFS(int u, vector<vector<int>> &adj, vector<bool> &visited){
        visited[u] = true;

        for(auto &v : adj[u]){
            if(!visited[v]){
                DFS(v, adj, visited);
            }
        }
        count++;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        int pairs = edges.size();
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);

      // Making adj list normally
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

      // Remaining elements which have not been visited yet
        long long remaining = n;
      // Variable 'ans' to store final ans
        long long ans = 0;
        for(int i = 0; i < n; i++){
          // updating count before the new DFS call
            count = 0;
          // Normal DFS call
            if(!visited[i]){
                DFS(i, adj, visited);
              // now we have count amount of nodes which we have visited so remaining nodes will be 'remaining - count'
                remaining = remaining - count;
              // Now the number of pairs will form with each reamining node to each visited node.
                long long combination = remaining * count;
              // add those formed pair in final ans.
                ans += combination;
            }
        }
      // at last return the final answer
        return ans;
    }
};


// METHOD 2: Using BFS ---> Logic remains the same

class Solution {
public:
    int count;
    void DFS(int u, vector<vector<int>> &adj, vector<bool> &visited){
        visited[u] = true;

        queue<int> que;
        que.push(u);

        while(!que.empty()){
            int node = que.front();
            que.pop();

            for(auto &v : adj[node]){
                if(!visited[v]){
                    visited[v] = true;
                    que.push(v);
                }
            }
            count++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        int pairs = edges.size();
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long remaining = n;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            count = 0;
            if(!visited[i]){
                DFS(i, adj, visited);
                remaining = remaining - count;
                long long combination = remaining * count;
                ans += combination;
            }
        }
        return ans;
    }
};
