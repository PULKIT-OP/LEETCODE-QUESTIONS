// Question Link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/

// METHOD 1: Using BITMASK and MULTISOURCE BFS
// Bitmask stores which nodes we have visited so far till currnet node

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        queue<pair<int, int>> q;
        set<pair<int, int>> seen;
        int globalMask = 1;
        for(int i = 0; i < n; i++){
            int bitmask = (1 << i);
            q.push({i, bitmask});
            seen.insert({i, bitmask});
            globalMask = globalMask | (1 << i);
        }

        int step = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto temp = q.front();
                q.pop();
                int node = temp.first;
                int mask = temp.second;

                if(mask == globalMask){
                    return step;
                }

                for(auto e : graph[node]){
                    int mask2 = mask | (1 << e);
                    if(seen.find({e, mask2}) == seen.end()){
                        q.push({e, mask2});
                        seen.insert({e, mask2});
                    }
                }
            }
            step++;
        }

        return -1;
    }
};
