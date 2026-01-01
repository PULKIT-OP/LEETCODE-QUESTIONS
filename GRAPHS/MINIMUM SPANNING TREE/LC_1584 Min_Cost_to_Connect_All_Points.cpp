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
