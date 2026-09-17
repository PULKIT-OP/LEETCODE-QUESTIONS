// Question Link: https://leetcode.com/problems/find-if-path-exists-in-graph/


// METHOD 1: Using DFS


class Solution {
public:
    bool found = false;
    void DFS(vector<vector<int>>& adj, vector<bool> &visited, int src, int destination){
        visited[src] = true;
        if(src == destination){
            found = true;
            return;
        }

        for(auto &e : adj[src]){
            if(!visited[e]){
                DFS(adj, visited, e, destination);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> adj(n);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);

        DFS(adj, visited, source, destination);

        return found;
    }
};


// METHOD 2: Using BFS

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> adj(n);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == destination){
                return true;
            }

            for(auto &e : adj[node]){
                if(!visited[e]){
                    q.push(e);
                    visited[e] = true;
                }
            }
        }

        return false;
    }
};
