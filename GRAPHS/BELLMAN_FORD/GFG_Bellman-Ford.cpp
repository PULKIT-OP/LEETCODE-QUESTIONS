// Question Link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

// Bellman-Ford is used to get the shortest path from the source to all the nodes or target node even if it has negative edge weight.
// MOST IMPORTANT ----> It is different from FLOYD WARSHALL, it cant get shortest distance for all pairs of nodes, but from a souce node to all other nodes.
// It is also used to detect if any graph have negative cycle in it.
// This Algorithm says you just have to relax the all the edges "V-1" times, and you will get your answer. And If you try to do relaxation more than V-1 times then no change in the answer will happen.
// If any change happens after V-1 relaxations then -ve cycle is present in that graph.
// The real reason why only V-1 times relaxation?? --> Because in the worst case scenario an vertex is connected to all other vertex with v-1 edges so we need to iterate all those edges thats why v-1
// Bellman-Ford is only possible with DIRECTED GRAPHS if you have undirected graph then you must first convert it in directed graph.
// Bellman-Ford can handle -ve edges.
// Mostly it is a follow-up of Dijkstra's Algorithm in an interview.

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

        vector<int>  result(V, 1e8);
        result[src] = 0;
        
        for(int i = 1; i < V; i++){
            for(auto &e : edges){
                int u = e[0];
                int v = e[1];
                int w = e[2];

              // Relaxation : If distance to reach u is not infinity and distance to reach 'u' from source + 'w'(distance to reach v from u) is smaller than distace to reach v from source than update it
              // Bhai in simple terms: result[u] ---> distace to reach u from source 
              //                       w ----> distance to reach v from u 
              //                       result[v] ----> distance to reach v from source 
              // and we have to options to reach v either you go directly to node v from source or or or you first go to node u and then from there you go to node v both route will have their own distance you just have to use the shortest one
                if(result[u] != 1e8 && result[u] + w < result[v]){
                    result[v] = result[u] + w;
                }
            }
        }

      // after this v-1 iteration you will get your answer in results vector.

      // Now you just need to check if any cycle is present ----> if any other update happens in edge than there must be a cycle.
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
                
            if(result[u] != 1e8 && result[u] + w < result[v]){
                return {-1};
            }
        }
        
        return result;
    }
};
