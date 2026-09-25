// Question Link: https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/


// METHOD 1: Using Bipartite + DFS + BFS Method

class Solution {
public:
    bool isBipartite(int x, unordered_map<int, vector<int>> &adj, vector<int> &mark, int color){
        mark[x] = color;

        for(auto e : adj[x]){
            if(mark[e] == color){
                return false;
            }
            if(mark[e] == -1){
                if(isBipartite(e, adj, mark, 1-color) == false){
                    return false;
                }
            }
        }

        return true;
    }

    int maxGroupFromEachComponents(int x, unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<int> &levels){
        visited[x] = true;
        int maxGrp = levels[x];

        for(auto e : adj[x]){
            if(!visited[e]){
                maxGrp = max(maxGrp, maxGroupFromEachComponents(e, adj, visited, levels));
            }
        }

        return maxGrp;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        int m = edges.size();

      // Making adj list
        unordered_map<int, vector<int>> adj;
        for(auto e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

      // checking if the graph is bipartite or not, if not bipartite return -1 we cant split it into groups
        vector<int> mark(n+1, -1);
        for(int i = 1; i <= n; i++){
            if(mark[i] == -1 && isBipartite(i, adj, mark, 0) == false){
                return -1;
            }
        }

      // Now finding possible groups(levels) from each node 1 to n
        vector<int> possible_groups(n+1, 0);
        for(int i = 1; i <= n; i++){
            vector<bool> visited(n+1, false);
            queue<int> q;
            q.push(i);
            visited[i] = true;
            int groups = 0;
            while(!q.empty()){
                int size = q.size();
                while(size--){
                    int node = q.front();
                    q.pop();

                    for(auto e : adj[node]){
                        if(!visited[e]){
                            visited[e] = true;
                            q.push(e);
                        }
                    }
                }
                groups++;
            }

            possible_groups[i] = groups;
        }

      // as graph can be in multiple componenets so finding max group possible from each componenet and after adding that up we get our final answer
        vector<bool> visited(n+1, false);
        int maxGroup = 0;
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                maxGroup += maxGroupFromEachComponents(i, adj, visited, possible_groups);
            }
        }

      // return max group
        return maxGroup;

    }
};
