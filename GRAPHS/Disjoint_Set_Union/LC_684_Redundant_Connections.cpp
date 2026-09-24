// Question Link: https://leetcode.com/problems/redundant-connection/description/


// METHOD 1: Using DFS
// Making adj list and simultaneusly checking if the nodes reachable already if yes then current edge is redundant otherwise add the edge in adj lisst

class Solution {
public:
    int n;
    bool DFS(unordered_map<int, vector<int>> &adj, int u, int v, vector<bool> &visited){
        if(u == v){
            return true;
        }
        visited[u] = true;
        for(auto e : adj[u]){
            if(!visited[e] && DFS(adj, e, v, visited)){
                return true;
            }
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();

        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            vector<bool> visited(n+1, false);
            if(adj.find(u) != adj.end() && adj.find(v) != adj.end() && DFS(adj, u, v, visited)){
                return edges[i];
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};


// METHOD 2: Using BFS
// Same logic as above just different algorithm

class Solution {
public:
    int n;
    bool BFS(unordered_map<int, vector<int>> &adj, int u, int v, vector<bool> &visited){
        visited[u] = true;
        queue<int> q;
        q.push(u);

        while(!q.empty()){
            int node = q.front();
            if(node == v){
                return true;
            }
            q.pop();

            for(auto &e : adj[node]){
                if(!visited[e]){
                    visited[e] = true;
                    q.push(e);
                }
            }
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();

        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            vector<bool> visited(n+1, false);
            if(adj.find(u) != adj.end() && adj.find(v) != adj.end() && BFS(adj, u, v, visited)){
                return edges[i];
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};


// METHOD 3: Using DSU
// Combining nodes as they are in edges if I have combined a node already then currnet edge is redundant otherwise connect(Union) current edge

class Solution {
public:
    int find(int x, vector<int> &parent){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x], parent);
    }

    void Union(int x, int y, vector<int> &rank, vector<int> &parent){
        if(rank[x] > rank[y]){
            parent[y] = x;
        }
        else if(rank[y] > rank[x]){
            parent[x] = y;
        }
        else{
            parent[y] = x;
            rank[x]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parent(n+1);
        vector<int> rank(n+1, 1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }

        for(auto e : edges){
            int u = e[0];
            int v = e[1];

            int up = find(u, parent);
            int vp = find(v, parent);

            if(up == vp){
                return {u, v};
            }
            else{
                Union(up, vp, rank, parent);
            }
        }

        return {};
    }
};
