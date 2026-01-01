// Question Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

// PRIMS ALGORITHM is used to make MINIMUM SPANNING TREE ---> SPANNING TREE with minimum sum of (V - 1)edges.
// Here we use MIN_HEAP datastructure to store {weight, node} of any edge.
// and we calculate minimum sum of the edges possible 


// METHOD 1: If you have been asked to just find the sum of edges then this will be enough.
class Solution {
  public:
    typedef pair<int, int> P;
    int spanningTree(int V, vector<vector<int>>& edges) {      // edges[i] ---> [u, v, w] ----> current_node, destination_node, weight_of_edge
        // code here
      // Defining Priority Queue of Pair ---> {weight,kaha jana hai}
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});     // {weight, kaha jana hai}
      // to store total minimum sum possible
        int sum = 0;
      // making adj list from the edges given
        vector<vector<P>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});   // {v, weight}
            adj[v].push_back({u, w});
        }

      // tracking the visited nodes
        vector<bool> inMST(V, false);

      // run while queue is not empty
        while(!pq.empty()){
            int w = pq.top().first;
            int node = pq.top().second;
            pq.pop();
          // check is we already visited this node if yes then move to next node leave this one
            if(inMST[node]){
                continue;
            }
          // if not visited then add its weight in sum
            sum += w;
          // and mark it visited
            inMST[node] = true;

          // then iterate on neighbour ---> to which node I can go from my current node
            for(auto &e : adj[node]){
                int w2 = e.second;
                int n = e.first;
                // if not visited this node then push in queue for further process
                if(inMST[n] != true){
                    pq.push({w2, n});
                }
            }
        }

      // at last return the total sum of edges of MST
        return sum;
    }
};


// MEHTOD 2: If you have been asked the path or info about parents of each node then use this one

class Solution {
  public:
    typedef vector<int> P;
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push([0, 0, -1]);     // {weight, kaha jana hai, parent(abhi kaha pr ho)}
        int sum = 0;
        vector<vector<P>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});   // {v, weight}
            adj[v].push_back({u, w});
        }
        
        vector<bool> inMST(V, false);
      // storing parent of each node, initially none of them have parents
        vector<int> parent(V, -1);
        while(!pq.empty()){
            int w = pq.top()[0];
            int node = pq.top()[1];
            int par = pq.top()[2];
            pq.pop();
            if(inMST[node]){
                continue;
            }
            sum += w;
            inMST[node] = true;
          // storing parent of node here
            parent[node] = par;
            
            for(auto &e : adj[node]){
                int w2 = e.second;
                int n = e.first;
                
                if(inMST[n] != true){
                    pq.push({w2, n, node});  // pushing {weight of edge, kaha jana hai, (parent)abhi kaha pr ho}
                }
            }
        }

      // return ans according to your question not this one.
        return sum;
    }
};
