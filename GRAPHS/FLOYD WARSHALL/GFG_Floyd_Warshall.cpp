// Question Link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1


// FLOYD WARSHALL Algorithm is used to get shortest path from all Vertices to all the Vertices in a Wieghted-Directed Graph.
// MOST IMPORTANT ---> It is different from BELLMAN_FORD, as that algo cant compute shortest distance for all pairs of nodes but can only compute shortest distance form a source node to all other nodes.
// It can detect -ve cycle as well
// You just need to traverse through each edge in the graph via each node and if you find any better distance keep updating ---> This will be of O(n^3) complexity
// To detect -ve cycle you just need to check each diagonal element if it has any value other than 0 after the above step.

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {

        int n = dist.size();
        
        for(int via = 0; via < n; via++){
            
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][j] > dist[i][via] + dist[via][j] && dist[i][via] < 1e8 && dist[via][j] < 1e8){
                        dist[i][j] = dist[i][via] + dist[via][j];
                    }
                }
            }
        }
    }
};
