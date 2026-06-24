// Question Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

// METHOD 1: Using DFS

class Solution {
public:
    void DFS(int idx, vector<vector<int>>& stones, vector<bool> &visited){
        visited[idx] = true;

        for(int i = 0; i < stones.size(); i++){
          // if stone is not visited and stone x cordinate or y cordinate is same then call DFS
            if(visited[i] == false && (stones[i][0] == stones[idx][0] || stones[i][1] == stones[idx][1])){
                DFS(i, stones, visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
      // number of stones 
        int n = stones.size();
      // marking if a node is visited
        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; i++){
          // if stone not visited Call DFS
            if(visited[i] == false){
                DFS(i, stones, visited);
                count++;
            }
        }

        return n - count;
    }
};


// METHOD 2: Using DSU

class Solution {
public:
    int find(int x, vector<int> &parent){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x], parent);
    }

    void Union(int x, int y, vector<int> &parent, vector<int> &rank){
        int x_p = find(x, parent);
        int y_p = find(y, parent);

        if(x_p == y_p){
            return;
        }

        if(rank[x_p] > rank[y_p]){
            parent[y_p] = x_p;
        }
        else if(rank[y_p] > rank[x_p]){
            parent[x_p] = y_p;
        }
        else{
            parent[x_p] = y_p;
            rank[y_p]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        for(auto &e : stones){
            maxRow = max(maxRow, e[0]);
            maxCol = max(maxCol, e[1]);
        }

        vector<int> parent(maxRow + maxCol + 2);
        vector<int> rank(maxRow + maxCol + 2, 0);
        unordered_map<int, int> stoneNodes;    // to store nodes where stone is present

        for(int i = 0; i < parent.size(); i++){
            parent[i] = i;
        }

        for(auto &e : stones){
            int u = e[0];
            int v = e[1] + maxRow + 1;

            Union(u, v, parent, rank);
            // updating stonenodes with row and col where stone is present
            stoneNodes[u] = 1;
            stoneNodes[v] = 1;
        }

        int count = 0;
        for(auto &it : stoneNodes){
            if(find(it.first, parent) == it.first){
                count++;
            }
        }

        return n - count;
    }
};
