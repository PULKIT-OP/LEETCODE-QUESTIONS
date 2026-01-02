// Question Link: https://leetcode.com/problems/min-cost-to-connect-all-points/description/

// There is nothing in this question it's just a application of Prim's Algorithm, We have just pasted the same prims algo here.
// You just need to make a adjency list to pass in your prims algorithm rest the algorithm will handle.

// METHOD 1: PRIM's Algorithm

class Solution {
public:
    // This is the Standard or normal prims algo nothing new
    int primsAlgo(vector<vector<pair<int, int>>> &adj, int V){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        vector<bool> inMST(V, false);
        int sum = 0;
        while(!pq.empty()){
            int w = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(inMST[node]){
                continue;
            }
            inMST[node] = true;
            sum += w;

            for(auto &e : adj[node]){
                int w2 = e.second;
                int n = e.first;

                if(inMST[n] == false){
                    pq.push({w2, n});
                }
            }
        }

        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int xi = points[i][0];
                int yi = points[i][1];
                int xj = points[j][0];
                int yj = points[j][1];

                int w = abs(xi - xj) + abs(yi - yj);

              // Dont get confused here, we are just mapping the points nothing much, you must be thinking why we are not using coordinates to map ---> just because we dont have to you just need the number or index of the two points and the weight or distance bw them so we are doing the same we are just mapping the point numbers like this : point 1 --> {point 2, 3}.  Because all points are unique so we can do this.
                adj[i].push_back({j, w});       // here we are mapping ith point to jth point with weight bw them
                adj[j].push_back({i, w});      // mapping jth point to ith point with weight bw them
            }
        }

        return primsAlgo(adj, n);
    }
};


// MEHTOD 2: Using Kruskal's Algorithm

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int x_par = find(x);
        int y_par = find(y);

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
    int kruskalAlgo(vector<vector<int>> &adj){
        auto lambda = [&](vector<int> &v1, vector<int> &v2){
            return v1[2] < v2[2];
        };

        sort(adj.begin(), adj.end(), lambda);
        int sum = 0;
        for(auto &e : adj){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            int u_par = find(u);
            int v_par = find(v);

            if(u_par != v_par){
                Union(u, v);
                sum += w;
            }
        }

        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);    // resizing parent according to question
        rank.resize(n, 0);   // resizing rank according to question

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        // Making adj list of type ---> adj[i] = {u, v, w}
        vector<vector<int>> adj;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int xi = points[i][0];
                int yi = points[i][1];
                int xj = points[j][0];
                int yj = points[j][1];

                int w = abs(xi - xj) + abs(yi - yj);

                adj.push_back({i, j, w});       // here we are mapping ith point to jth point with weight bw them
            }
        }
        // At last just call Kruskal's Algo you will get Ans
        return kruskalAlgo(adj);
    }
};

/*

Which algo is best ??? What to use ???

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
