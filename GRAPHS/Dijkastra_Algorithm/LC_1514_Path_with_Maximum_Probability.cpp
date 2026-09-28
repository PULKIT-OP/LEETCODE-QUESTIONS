// Question Link: https://leetcode.com/problems/path-with-maximum-probability/description/


// METHOD 1: Using Dijkstra's Algorithm

class Solution {
public:
    typedef pair<double, int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;
        int size = edges.size();
        for(int i = 0; i < size; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }
      
        vector<double> maxProb(n+1, INT_MIN);
        priority_queue<P> pq;  // Here we are not finding minimum, so structure of priority_queue is quite strange
        pq.push({1.0, start_node});

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int node = temp.second;
            double prob = temp.first;

            if(node == end_node){
                return prob;
            }

            for(auto e : adj[node]){
                double prob_ = e.second;
                int neigh = e.first;

                if(prob_*prob > maxProb[neigh]){
                    maxProb[neigh] = prob*prob_;
                    pq.push({maxProb[neigh], neigh});
                }
            }
        }

        return 0;
    }
};
