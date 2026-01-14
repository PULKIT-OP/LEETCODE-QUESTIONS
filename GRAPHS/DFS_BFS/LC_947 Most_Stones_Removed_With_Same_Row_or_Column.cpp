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
