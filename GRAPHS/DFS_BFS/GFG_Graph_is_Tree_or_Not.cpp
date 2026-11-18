// Question Link: https://www.geeksforgeeks.org/problems/is-it-a-tree/1


// METHOD 1: Using DFS

class Solution {
  public:
    unordered_map<int, vector<int>> adj;
    int count = 0;
    void DFS(int src, vector<bool> &visited){
        visited[src] = true;
        count++;
        
        for(auto &e : adj[src]){
            if(!visited[e]){
                DFS(e, visited);
            }
        }
    }
    bool isTree(int n, int m, vector<vector<int>> &edges) {
        // code here
        if(m != n-1){
            return false;
        }
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        DFS(0, visited);
        
        return count == n;
    }
};



// METHOD 2: Using BFS

class Solution {
  public:
    unordered_map<int, vector<int>> adj;
    int N;
    int count = 0;
    void BFS(){
        vector<bool> visited(N, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        count++;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto &e : adj[node]){
                if(!visited[e]){
                    q.push(e);
                    visited[e] = true;
                    count++;
                }
            }
        }
    }
    bool isTree(int n, int m, vector<vector<int>> &edges) {
        // code here
        if(m != n-1){
            return false;
        }
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        N = n;
        BFS();
        
        return count == n;
    }
};


// METHOD 3: Using UNION FIND

class Solution {
  public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y){
        if(rank[x] > rank[y]){
            parent[y] = x;
        }
        else if(rank[y] > rank[x]){
            parent[x] = y;
        }
        else{
            parent[x] = y;
            rank[y]++;
        }
    }
    bool isTree(int n, int m, vector<vector<int>> &edges) {
        // code here
        parent.resize(n);
        rank.resize(n, 1);
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        int count = 0;
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            
            int up = find(u);
            int vp = find(v);
            
            if(up == vp){
                return false;
            }
            else{
                Union(up, vp);
                count++;
            }
        }
        
        return count == n-1;
        
    }
};
