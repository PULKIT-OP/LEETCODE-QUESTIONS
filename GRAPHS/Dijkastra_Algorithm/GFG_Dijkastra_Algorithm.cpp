// Question Link: 

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
      // Making priority Queue which store pairs first --> cost/dist, and second --> node
      // this queue stores the minimum cost required to reach some node so if you find anything like this push in this queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;       //cost, node
      // This vector store the minimum cost required to reach that node from source
        vector<int> minDist(V, INT_MAX);
        minDist[src] = 0;      // Cost required from source to source will be none
        pq.push({0, src});

      // makin adj list
        vector<vector<pair<int, int>>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }

      // continue till que is not empty
        while(!pq.empty()){
            int node = pq.top().first;      // Storing que top
            int d = pq.top().second;        // cost required to reach 'node' from source
            pq.pop();

          // now checking all the neighbours 
            for(auto &v : adj[node]){
                int dist = v.first;
                int neigh = v.second;

              // cost required to reach 'neigh' is d + dist because first you go to 'node' from source then from 'node' you come to its neighbour which is 'neigh' so you have to add both the costs
              // If the total cost required to reach this 'neigh' is smaller than the previous cost you found or stred in minDist then update it.
              // and push it in queue as well because you found a new small cost.
                if(d + dist < minDist[neigh]){
                    minDist[neigh] = d + dist;
                    pq.push({d + dist, neigh});
                }
            }
        }

      // then at last return the minDist array which has all then nodes with min cost required to reach
        return minDist;
    }
};
