// Question Link: https://leetcode.com/problems/possible-bipartition/description/


// METHOD 1: Using DFS

class Solution {
public:
    bool DFS(int x, unordered_map<int, vector<int>> &adj, int group, vector<int> &mark){
        mark[x] = group;

        for(auto e : adj[x]){
            if(mark[e] == group){
                return false;
            }
            if(mark[e] == -1){
                int marking = 1 - group;
                if(DFS(e, adj, marking, mark) == false){
                    return false;
                }
            }
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int m = dislikes.size();

        unordered_map<int, vector<int>> adj;
        for(auto e : dislikes){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> mark(n+1, -1);

        for(auto e : adj){
            int node = e.first;
            if(mark[node] == -1 && !DFS(node, adj, 0, mark)){
                return false;
            }
        }

        return true;
    }
};

// METHOD 2: Using BFS

class Solution {
public:
    bool BFS(int x, unordered_map<int, vector<int>> &adj, int group, vector<int> &mark){
        mark[x] = group;
        queue<int> q;
        q.push(x);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            int sign = mark[node];
            for(auto e : adj[node]){
                if(mark[e] == sign){
                    return false;
                }
                if(mark[e] == -1){
                    int marking = 1 - sign;
                    q.push(e);
                    mark[e] = marking;
                }
            }
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int m = dislikes.size();

        unordered_map<int, vector<int>> adj;
        for(auto e : dislikes){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> mark(n+1, -1);

        for(auto e : adj){
            int node = e.first;
            if(mark[node] == -1 && !BFS(node, adj, 0, mark)){
                return false;
            }
        }

        return true;
    }
};
