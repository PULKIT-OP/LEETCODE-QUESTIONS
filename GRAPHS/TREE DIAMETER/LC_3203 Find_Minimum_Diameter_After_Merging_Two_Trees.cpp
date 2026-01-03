// Question Link: https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/

// Just keep these points in mind while attempting this or similar question which has diameter kinda thing:
// If you choose any random vertex(x) in graph and try to find a vertex(y) which is farthest from this random vertex(x) than the vertex(y) will be one of the end of diameter of the tree
// And similarly from the vertex(y) try to find the farthest node(m) this node will be other end of the diameter, now you got both the ends of diameter.

// In this question you just need to connect two trees/graphs with one edge bw any two vertices
// You just find out value of diameter from both the trees and then then find ciel(diameter + 1)/2 of both the trees then your ans will be maximum of these three values


class Solution {
public:
    pair<int, int> BFS(int u, vector<vector<int>> &adj){
        queue<int> que;
        que.push(u);

        unordered_map<int, bool> visited;
        visited[u] = true;

        int distance = 0;
        int farthest_node = u;

        while(!que.empty()){
            int size = que.size();

            while(size--){
                int curr = que.front();
                que.pop();
                farthest_node = curr;

                for(auto &e : adj[curr]){
                    if(!visited[e]){
                        visited[e] = true;
                        que.push(e);
                    }
                }
            }
            if(!que.empty()){
                distance++;
            }
        }

        return {farthest_node, distance};
    }

    int findDiameter(vector<vector<int>>& adj){
        // find longest distance from a random node which is 0
        auto [farthest_node, dist] = BFS(0, adj);

        // this farthest_node will be our one end of the diameter of the tree
        // now find fattherst node from this node you got and that will be the other end of the diameter
        auto [other_end, diameter] = BFS(farthest_node, adj);

        return diameter;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();

        vector<vector<int>> adj1(n+1);
        vector<vector<int>> adj2(m+1);

        for(auto &e : edges1){
            int u = e[0];
            int v = e[1];

            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(auto &e : edges2){
            int u = e[0];
            int v = e[1];

            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        int diameter_1 = findDiameter(adj1);
        int diameter_2 = findDiameter(adj2);

        int minDiameter = ((diameter_1 + 1)/2) + ((diameter_2 + 1)/2) + 1;

        return max({diameter_1, diameter_2, minDiameter});
    }
};
