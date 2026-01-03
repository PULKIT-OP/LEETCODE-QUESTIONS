// Question Link: https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1



// METHOD 1: 

class Solution {
  public:
    void DFS(int u, vector<int> adj[], vector<bool> &visited){
        visited[u] = true;
        
        for(auto it = adj[u].begin(); it != adj[u].end(); it++){
            int neigh = *it;
            if(visited[neigh] == false){
                DFS(neigh, adj, visited);
            }
        }
    }
    bool isConnected(vector<int> adj[], int V){
      // Firstly finding first non zero degree node to start our dfs
      // its basic idea is this, that if the nodes are connected than it must have non zero degree node and all the nodes, so you just have to find one such node
        int nonZero = -1;
        for(int i = 0; i < V; i++){
            if(adj[i].size() != 0){
                nonZero = i;
                break;
            }
        }

      // if you find no non zero degree nodes means this has no edge and means its a EULER CIRCUIT so return true
        if(nonZero == -1){
            return true;
        }

      // and if you find one such node then call DFS from that vertex
        vector<bool> visited(V, false);
        DFS(nonZero, adj, visited);

      // After DFS if you find any non visited node and its degree is not zero menas it was not connected together so return false ohterwise return true
        for(int i = 0; i < V; i++){
            if(visited[i] == false && adj[i].size() > 0){
                return false;
            }
        }
        
        return true;
    }
    bool isEularCircuitExist(int v, vector<int> adj[]) {

        // check if all non zero degree nodes are coonnected
        if(isConnected(adj, v) == false){
            return 0;
        }
        
        // find euler circuit
      // If odd degree nodes count is greater than zero than it is noothing : no EULER PATH and no EULER CIRCUIT
      // If it has exactly 2 odd degree nodes than it has EULER PATH and no EULER CIRCUIT
      // And if it has no ODD degree nodes than it is EULER CIRCUIT.

      // Here we are finidng number of odd degree nodes
        int odd = 0;
        for(int i = 0; i < v; i++){
            if(adj[i].size() % 2 != 0){
                odd++;
            }
        }

      // I m doing as queston asked but you have to keep in mind all the points that i have shared above
        if(odd == 0){
            return 1;
        }
        return 0;
    }
};
