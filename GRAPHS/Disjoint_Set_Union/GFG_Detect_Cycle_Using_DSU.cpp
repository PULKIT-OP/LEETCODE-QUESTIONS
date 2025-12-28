// Question Link: https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1


// In both methods you can either use normal version of find() and Union() or the optimized version which uses RANK and PATH compression.
// METHOD 1: Using DSU with RANK and PATH COMPRESSION

class Solution {
  public:
  
int find(int x, vector<int> &parent){
        if(parent[x] == x){
            return x;
        }
        
        return parent[x] = find(parent[x], parent);
}
    
void union_DSU(int x, int y, vector<int> &parent, vector<int> &rank){
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
            rank[x_par]++;
            parent[y_par] = x_par;
        }
}
bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> rank(V, 0);
        vector<int> parent(V);
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
        
        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            
            int u_par = find(u, parent);
            int v_par = find(v, parent);
            
            if(u_par == v_par){
                return true;
            }
            union_DSU(u, v, parent, rank);
        }
      
        return false;
    }
};

//  METHOD 2: Here also we are using RANK and PATH COMPRESSION but here we are using adj list as well 


class Solution {
  public:
  
    int find(int x, vector<int> &parent){
        if(parent[x] == x){
            return x;
        }
        
        return parent[x] = find(parent[x], parent);
    }
    
    void union_DSU(int x, int y, vector<int> &parent, vector<int> &rank){
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
            rank[x_par]++;
            parent[y_par] = x_par;
        }
    }
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> rank(V, 0);
        vector<int> parent(V);
        
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
        
        for(int u = 0; u < V; u++){
            for(auto &v : adj[u]){
                if(u < v){
                    int u_par = find(u, parent);
                    int v_par = find(v, parent);
                    
                    if(u_par == v_par){
                        return true;
                    }
                    
                    union_DSU(u, v, parent, rank);
                }
            }
        }
        
        return false;
        
    }
};
