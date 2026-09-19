// Question Link: https://leetcode.com/problems/all-paths-from-source-to-target/description/


// METHOD 1: Using DFS traversal + Backtracking

class Solution {
public:
    int n;
    void DFS(vector<vector<int>>& graph, int i, vector<int> &temp, vector<vector<int>> &result){
        temp.push_back(i);
        
        if(i == n-1){
            result.push_back(temp);
            temp.pop_back();
            return;
        }

        for(auto &e : graph[i]){
            DFS(graph, e, temp, result);
        }

        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();

        vector<int> temp;
        vector<vector<int>> result;

        DFS(graph, 0, temp, result);

        return result;
    }
};
