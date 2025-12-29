// Question Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/


// METHOD 1: USING DSU ----> UNION-FIND

class Solution {
public:
    int find(int x, vector<int> &parent){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x], parent);
    }

    void Union(int x, int y, vector<int> &parent, vector<int> &rank){
        int x_par = find(x, parent);
        int y_par = find(y, parent);

        if(x_par == y_par){
            return;
        }
        if(rank[x_par] > rank[y_par]){
            parent[y_par] = x_par;
        }
        else if(rank[y_par] > rank[x_par]){
            parent[x_par] = y_par;
        }
        else{
            parent[x_par] = y_par;
            rank[y_par]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        vector<int> parent(n);
        vector<int> rank(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        int components = n;

        for(auto &v : connections){
            int x = v[0];
            int y = v[1];

            int x_par = find(x, parent);
            int y_par = find(y, parent);

            if(x_par != y_par){
                Union(x, y, parent, rank);
                components--;
            }
        }

        return components - 1;
    }
};


// METHOD 2: Using Noraml GRAPH TRAVERSAL (DFS)

class Solution {
public:
    void DFS(int u, vector<vector<int>> &adj, vector<bool> &visited){
        visited[u] = true;

        for(auto &v : adj[u]){
            if(!visited[v]){
                DFS(v, adj, visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }

        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        int components = 0;

        for(auto &vec : connections){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                DFS(i, adj, visited);
                components++;
            }
        }

        return components - 1;
    }
};

// Using BFS Traversal    ---> Logic is same as above just different algorithm usage.

class Solution {
public:
    void BFS(int u, vector<vector<int>> &adj, vector<bool> &visited){
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
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }

        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        int components = 0;

        for(auto &vec : connections){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                BFS(i, adj, visited);
                components++;
            }
        }

        return components - 1;
    }
};
