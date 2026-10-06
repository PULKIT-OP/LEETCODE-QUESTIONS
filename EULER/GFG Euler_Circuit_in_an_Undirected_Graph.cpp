// Question Link: https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1

// LITTLE THEORY ABT EULER
// EULARIAN PATH ---> A path in graph in which you use each edge only once
// EULARIAN CIRCUIT ---> A graph in which from whereever you start you will end up at start node at last after visiting all edges only once
// Not all graph will have EULARIAN CIRCUIT
// If a graph is not EULARIAN CIRCUIT ---> Then either you will not be able to visit all edges or you cant come back to start node after visiting all edges at the end

// For having EULER PATH all vertices with non zero degree MUST belong to a single connected component
// All vertices have EVEN DEGREES if it has EULARIAN CIRCUIT
// If a graph has EULER PATH and does not have EULER CIRCUIT then it is SEMI-EULARIAN GRAPH
// If a graph has EULER CIRCUIT then it must be having EULER PATH and vice verca is NOT TRUE

// In SEMI-EULARIAN GRAPH (which has only EULARIAN PATH no EULER CIRCUIT) will have odd degree at starting and ending node

// HOW TO SPOT THAT IT IS A EULER GRAPH QUESTION?? ---> It will contain these keywords --> "use all only once", "visit all only once"

// FOR DIRECTED GRAPH: 
// Most of the things remains same, that it should visit all edges, start and end at same node and all that shii reamins same
// Important part is this: here diffrence between inDegree and outDegree of start node is 1, and same goes for end node as well ---> It is for semi eularian graph
// All other nodes will have indgree == outdegree ---> for semi eularian graph and eularian graph as well



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
