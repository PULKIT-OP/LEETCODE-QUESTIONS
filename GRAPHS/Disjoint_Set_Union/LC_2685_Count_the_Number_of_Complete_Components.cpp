// Question Link: https://leetcode.com/problems/count-the-number-of-complete-components/description/

// METHOD 1:

class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &adj, int x, vector<bool> &visited, vector<int> &vertices){
        if(visited[x]){
            return;
        }
        visited[x] = true;
        vertices.push_back(x);
        for(auto e : adj[x]){
            if(visited[e] == false){
                DFS(adj, e, visited, vertices);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<vector<bool>> edgePresent(n, vector<bool>(n, false));
        for(auto e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            edgePresent[u][v] = true;
            edgePresent[v][u] = true;
        }

        unordered_map<int, vector<int>> component_vertex;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                vector<int> vertices;
                DFS(adj, i, visited, vertices);
                component_vertex[i] = vertices;
            }
        }

        int result = 0;
        for(auto e : component_vertex){
            vector<int> vec = e.second;
            int total_vertices = vec.size();
            bool complete = true;
            
            for(auto v : vec){
                if(adj[v].size() != total_vertices - 1){
                    complete = false;
                }
            }
            if(complete == true){
                result++;
            }
        }

        return result;

    }
};



// METHOD 2: Using DFS and can be done using BFS as well
// Although we are using DFS in previous method as well but there dfs is just a small part of the solution but here the major part is dfs only

class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &adj, int x, vector<bool> &visited, int &vertices, int &edges){
        if(visited[x]){
            return;
        }
        visited[x] = true;
        vertices++;
        edges += adj[x].size();
        for(auto e : adj[x]){
            if(visited[e] == false){
                DFS(adj, e, visited, vertices, edges);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int result = 0;
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                int vertices = 0;
                int edges = 0;
                DFS(adj, i, visited, vertices, edges);
                if((edges/2) == (vertices*(vertices-1)/2)){
                    result++;
                }
            }
        }

        return result;

    }
};


// METHOD 3: Using DSU because its asking for components so just think abt DSU

class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int xp = find(x);
        int yp = find(y);
        if(xp == yp){
            return;
        }
        if(size[xp] > size[yp]){
            parent[yp] = xp;
            size[xp] += size[yp];
        }
        else if(size[yp] >= size[xp]){
            parent[xp] = yp;
            size[yp] += size[xp];
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(auto e : edges){
            int u = e[0];
            int v = e[1];

            dsu.Union(u, v);
        }

        unordered_map<int, int> rootToEdge;
        for(auto e : edges){
            int u = e[0];
            int v = e[1];

            int root = dsu.find(u);
            rootToEdge[root]++;
        }

        int result = 0;
        for(int i = 0; i < n; i++){
            if(dsu.find(i) == i){
                int vertices = dsu.size[i];
                int edges = rootToEdge[i];
                if((vertices*(vertices-1)/2) == edges){
                    result++;
                }
            }
        }

        return result;
    }
};
