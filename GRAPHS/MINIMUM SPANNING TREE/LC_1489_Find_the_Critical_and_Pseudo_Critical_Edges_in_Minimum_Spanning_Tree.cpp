// Question Link: https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/

// METHOD 1: Using KRUSKAL's Algorithm ---> DSU logic
// sort edges with edge weight
// first find out MST_WEIGHT --> Using kruskal's Algo
// then with try to exclude each edge one by one and check if you get increased edge weight ----> If yes then this edge is critical
// If edge weight is not critical, in this case --> make this edge compulsory and try to get MST_weight again using kruskals algo --> if you get same MST_WEIGHT then its pseudo_critical
// if not then its not PseudoCritical edge

class Solution {
public:
    int find(int x, vector<int> &parent){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x], parent);
    }
    void Union(int x, int y, vector<int> &parent, vector<int> &rank){
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
    int kruskal(int n, vector<vector<int>>& edges){
        vector<int> parent(n);
        vector<int> rank(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        int mstWeight = 0;
        int count = 0;
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            int idx = e[3];

            int up = find(u, parent);
            int vp = find(v, parent);

            if(up != vp){
                Union(up, vp, parent, rank);
                mstWeight += w;
                count++;
            }
        }

        if(count != n-1){
            return INT_MAX;
        }
        return mstWeight;
    }
    int newKruskal(int n, vector<int> boycotEdge, vector<vector<int>>& edges){
        vector<int> parent(n);
        vector<int> rank(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        int mstWeight = 0;
        int count = 0;
        for(auto e : edges){
            if(e == boycotEdge){
                continue;
            }
            int u = e[0];
            int v = e[1];
            int w = e[2];
            int idx = e[3];

            int up = find(u, parent);
            int vp = find(v, parent);

            if(up != vp){
                Union(up, vp, parent, rank);
                mstWeight += w;
                count++;
            }
        }
        
        if(count != n-1){
            return INT_MAX;
        }

        return mstWeight;
    }
    int forKruskal(int n, vector<int> boycotEdge, vector<vector<int>>& edges){
        vector<int> parent(n);
        vector<int> rank(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        Union(boycotEdge[0], boycotEdge[1], parent, rank);

        int mstWeight = boycotEdge[2];
        int count = 1;
        for(auto e : edges){
            if(e == boycotEdge){
                continue;
            }
            int u = e[0];
            int v = e[1];
            int w = e[2];
            int idx = e[3];

            int up = find(u, parent);
            int vp = find(v, parent);

            if(up != vp){
                Union(up, vp, parent, rank);
                mstWeight += w;
                count++;
            }
        }
        
        if(count != n-1){
            return INT_MAX;
        }

        return mstWeight;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
      // Pushing idx in each edge
        int i = 0;
        for(auto &e : edges){
            e.push_back(i);
            i++;
        }

      // sorting edges on edge weight
        vector<vector<int>> tempEdges = edges; 
        auto lambda = [&](vector<int> v1, vector<int> v2){
            return v1[2] < v2[2];
        };
        sort(tempEdges.begin(), tempEdges.end(), lambda);

        int MST_WEIGHT = kruskal(n, tempEdges);  // find MST_WEIGHT using kruskals algo

        vector<int> pseudoCriticalEdge; // to store pseudocriticaledge
        vector<int> criticalEdge; // to store criticaledge
        for(auto e : edges){
            int newWeight = newKruskal(n, e, tempEdges);  // now finding new weight excluding this edge 'e'
          // if newwight is greater then mst-weight then its critical edge so push in it
            if(newWeight > MST_WEIGHT){
                criticalEdge.push_back(e[3]);
            }
            else{
              // otherwise try to find mst-weight using this edge forcefully
                int forcedWeight = forKruskal(n, e, tempEdges);

              // if forceweight is equals to MST_WEIGHT then its pseudocriticaledge so push in it
                if(forcedWeight == MST_WEIGHT){
                    pseudoCriticalEdge.push_back(e[3]);
                }
            }
        }

      // at last return both vectors
        return {criticalEdge, pseudoCriticalEdge};
    }
};
