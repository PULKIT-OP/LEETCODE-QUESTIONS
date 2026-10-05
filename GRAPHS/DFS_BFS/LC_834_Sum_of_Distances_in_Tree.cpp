// Question Link: https://leetcode.com/problems/sum-of-distances-in-tree/description/

// METHOD 1: 

class Solution {
public:
    //store count of subtrees of each node
    long result_base_node = 0;
    vector<int> count;
    int N;
    int DFS1(unordered_map<int, vector<int>> &adj, int curr_node, int prev_node, int curr_depth) {
        int total_node = 1;
        
        result_base_node += curr_depth;
        
        for(int &child : adj[curr_node]) {
            if(child == prev_node)
                continue;
            
            total_node += DFS1(adj, child, curr_node, curr_depth+1);
        }
        
        //store count of subtrees of each node
        count[curr_node] = total_node;
        
        return total_node;
    }
    
    void DFS2(unordered_map<int, vector<int>> &adj, int parent_node, int prev_node, vector<int>& result) {
        
        for(int &child : adj[parent_node]) {
            if(child == prev_node)
                continue;
            
            result[child] = result[parent_node] - count[child] + (N - count[child]);
            DFS2(adj, child, parent_node, result);
        }
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        N = n;
        count.resize(n, 0);
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        result_base_node = 0;
        
        DFS1(adj, 0, -1, 0);
        
        vector<int> result(n, 0);
        
        result[0] = result_base_node;
        
        DFS2(adj, 0, -1, result);
        
        return result;
    }
};
