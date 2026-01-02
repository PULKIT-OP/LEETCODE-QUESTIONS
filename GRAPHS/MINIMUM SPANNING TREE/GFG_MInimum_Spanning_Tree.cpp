// Question Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1


// METHOD 1: USING PRIM's ALGORITHM

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


// METHOD 2: USING KRUSKAL's ALGORITHM ---> DSU (UNION-FIND)

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


/*
Which Algo is better Prim's or Kruskal's ??

Actually, they both have their strengths and weaknesses, and which one is "better" depends on the specific characteristics of the graph and the requirements of the problem. Here are some key points to consider:


1. Prim's Algorithm:
   - Prim's algorithm starts with a single vertex and grows the MST one vertex at a time.
   - It is often more efficient when the graph is dense (i.e., it has many edges relative to the number of vertices).
   - It typically has a lower time complexity on dense graphs, usually O(V^2) or O(V^2 + E), where V is the number of vertices and E is the number of edges.

2. Kruskal's Algorithm:
   - Kruskal's algorithm considers all edges in the graph and sorts them by weight, then adds edges to the MST in increasing order of weight while avoiding cycles.
   - It can be more efficient when the graph is sparse (i.e., it has few edges compared to the number of vertices).
   - It typically has a lower time complexity on sparse graphs, usually O(E log E), where E is the number of edges.

In summary, the choice between Prim's and Kruskal's algorithm depends on the characteristics of the graph and the specific requirements of the problem:

- Prim's algorithm is often preferred for dense graphs because of its lower time complexity in such cases.
- Kruskal's algorithm is generally preferred for sparse graphs due to its efficient use of sorting and simpler data structures.

Ultimately, the "better" algorithm depends on the context of the problem you are solving and the properties of the graph you are working with. It's important to analyze the characteristics of your specific problem and choose the algorithm that suits it best.

*/
