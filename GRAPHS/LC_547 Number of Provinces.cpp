// Question Link: https://leetcode.com/problems/number-of-provinces/description/

// DFS METHOD:
class Solution {
public:
    void DFS(int n, vector<vector<int>> &adj, vector<bool> &visited){
        if(visited[n]){
            return;
        }
        visited[n] = true;
        for(auto &v : adj[n]){
            if(!visited[v]){
                DFS(v, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int row = isConnected.size();
        int col = isConnected[0].size();

        vector<vector<int>> adj(row);    // always initialize adj with its size mentioned otherwise it will give runtime error

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(row, false);
        int count = 0;
        for(int i = 0; i < row; i++){
            if(!visited[i]){
                DFS(i, adj, visited);
                count++;
            }
        }
        return count;
    }
};


// BFS METHOD:
class Solution {
public:
    void BFS(int n, vector<vector<int>> &adj, vector<bool> &visited){
        if(visited[n]){
            return;
        }
        visited[n] = true;
        queue<int> que;
        que.push(n);
    
        while(!que.empty()){
            int node = que.front();
            que.pop();

            for(auto &v : adj[node]){
                if(!visited[v]){
                    visited[v] = true;
                    que.push(v);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int row = isConnected.size();
        int col = isConnected[0].size();

        vector<vector<int>> adj(row);

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(row, false);
        int count = 0;
        for(int i = 0; i < row; i++){
            if(!visited[i]){
                BFS(i, adj, visited);
                count++;
            }
        }
        return count;
    }
};
