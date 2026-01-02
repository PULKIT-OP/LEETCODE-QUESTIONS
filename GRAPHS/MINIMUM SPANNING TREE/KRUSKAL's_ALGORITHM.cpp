// Question Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

// KRUSKAL's Algorithm is used to find the MST from a spanning tree.
// This Algorithm is based on UNION-FIND (DSU) or we can say that this algo is a application of DSU.
// Here you just need to convert your given edges in a sorted vector, sort based on edge weight.
// We first compute edge with less weight.

// if you find parent of two nodes are same means they are connected and if not same then connect them with Union function and increment the sum withh edge weight


class Solution {
  public:
// Standard Find fucntion FROM DSU 
    int find(int x, vector<int> &parent){
        if(parent[x] == x){
            return x;
        }
        
        return parent[x] = find(parent[x], parent);
    }

// Standard Union code from DSU
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
    int spanningTree(int V, vector<vector<int>>& edges) {
        // in this quesion edges given was already in required format which is ----> {u, v, w} in a vector of vector
        // So we just need to sort it based on weight.

      // This is lambda function which is used in sorting our edges based on weight
        auto lambda = [&](vector<int> &v1, vector<int> &v2){
            return v1[2] < v2[2];
        };

      // sorting the edges
        sort(edges.begin(), edges.end(), lambda);

      // Making parent vector to store parent of each node
        vector<int> parent(V);
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
      // initializing rank vector
        vector<int> rank(V, 0);
        // storing minimum sum of the edges
        int sum = 0;

      //  Now iterating through each edge
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

          // finding parent of nodes
            int u_par = find(u, parent);
            int v_par = find(v, parent);

          // if parents are not same means both nodes are not connected so take union and increment the sum of weigbt
            if(u_par != v_par){
                Union(u, v, parent, rank);
                sum += w;
            }
        }
        // return your answer which is asked not this one.
        return sum;
    }
};
