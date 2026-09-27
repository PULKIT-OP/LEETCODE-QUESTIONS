// Question Link: https://leetcode.com/problems/build-a-matrix-with-conditions/description/

// METHOD 1: Using Topological sort with BFS (Kahn's Algorithm)

class TOPOSORT{
    public:
    vector<int> inDegree;
    unordered_map<int, vector<int>> adj;
    vector<int> topoOrder;

    TOPOSORT(int n, vector<vector<int>>& edges){
        inDegree.resize(n+1, 0);
        for(auto e : edges){
            int v = e[1];
            int u = e[0];
            inDegree[v]++;
            adj[u].push_back(v);
        }
    }

    void buildTopoSort(){
        queue<int> q;
        int n = inDegree.size();
        for(int i = 1; i < n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            for(auto &v : adj[node]){
                inDegree[v]--;

                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }
    }
};
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        TOPOSORT row(k, rowConditions);
        TOPOSORT col(k, colConditions);

        row.buildTopoSort();
        col.buildTopoSort();

        if(row.topoOrder.size() != k || col.topoOrder.size() != k){
            return {};
        }
      
        vector<vector<int>> result(k, vector<int> (k, 0));

        for(int i = 0; i < k; i++){
            int a = row.topoOrder[i];
            for(int j = 0; j < k; j++){
                if(col.topoOrder[j] == a){
                    result[i][j] = a;
                    break;
                }
            }
        }

        return result;
    }
};
