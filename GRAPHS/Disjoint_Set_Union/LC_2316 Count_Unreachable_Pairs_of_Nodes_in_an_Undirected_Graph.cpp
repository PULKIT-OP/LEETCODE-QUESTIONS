// Question Link: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

// METHOD 1: Using UNION-FIND(DSU)

class Solution {
public:
    int find(int x, vector<int> &parent){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x], parent);
    }

    void Union(int x, int y, vector<int> &parent, vector<int> &rank){
        int x_par = find(x, parent);
        int y_par = find(y, parent);

        if(x_par == y_par){
            return;
        }
        if(rank[x_par] > rank[y_par]){
            parent[y_par] = x_par;
        }
        else if(rank[y_par] > rank[x_par]){
            parent[x_par] = y_par;
        }
        else{
            parent[x_par] = y_par;
            rank[y_par]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(auto &e : edges){
            int x = e[0];
            int y = e[1];

            Union(x, y, parent, rank);
        }

        unordered_map<int, int> comp_size;
        for(int i = 0; i < n; i++){
            comp_size[find(i, parent)]++;
        } 
        
        long long ans = 0;
        long long remaining = n;
        for(auto &v : comp_size){
            long long size = v.second;
            remaining = remaining - size;
            ans += (remaining * size);
        }

        return ans;
    }
};
