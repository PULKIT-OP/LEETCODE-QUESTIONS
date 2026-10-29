// Question Link: https://leetcode.com/problems/palindromic-path-queries-in-a-tree/description

// SUGGESTION ---> Please dont try to solve this question, instead watch porn.

// METHOD 1: Using DFS, EULER PATH, LOWEST COMMON ANCESTOR, BINARY UPLIFTING, SEGMENT TREE  ---->  ALL IN ONE QUESTION

class Solution {
public:
    unordered_map<int, vector<int>> adj;
    int n;
    vector<int> tin, tout, eulerTour;
    vector<int> segmentTree;
    int timer;
    vector<vector<int>> ancestorTable;
    vector<int> depth;
    int cols;
    void DFS(int idx, int parent, int d, string &s){
        // Entering timer
        depth[idx] = d;
        ancestorTable[idx][0] = parent;
        tin[idx] = timer;
        eulerTour[timer] = 1 << (s[idx] - 'a');     // a = 001, b = 010 so on...
        timer++;

        for(auto e : adj[idx]){
            if(e != parent){
                DFS(e, idx, d+1, s);
            }
        }
        
        // Leaving time
        tout[idx] = timer;
        eulerTour[timer] = 1 << (s[idx] - 'a');
        timer++;
    }

    void buildSegmentTree(int root, int l, int r){
        if(l == r){
            segmentTree[root] = eulerTour[l];
            return;
        }

        int mid = l + (r-l)/2;
        buildSegmentTree(2*root+1, l, mid);
        buildSegmentTree(2*root+2, mid+1, r);

        segmentTree[root] = segmentTree[2*root+1] ^ segmentTree[2*root+2];
    }

    void updateSegmentTree(int idx, int val, int i, int l, int r){
        if(l == r){
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if(idx <= mid){
            updateSegmentTree(idx, val, 2*i+1, l, mid);
        }
        else{
            updateSegmentTree(idx, val, 2*i+2, mid+1, r);
        }

        segmentTree[i] = segmentTree[2*i+1] ^ segmentTree[2*i+2];
    }

    int searchSegmentTree(int start, int end, int idx, int l, int r){
        if(l > end || r < start){
            return 0;
        }
        if(l >= start && r <= end){
            return segmentTree[idx];
        }

        int mid = l + (r-l)/2;

        return searchSegmentTree(start, end, 2*idx+1, l, mid) ^ searchSegmentTree(start, end, 2*idx+2, mid+1, r);
    }

    void buildAncestorTable() {
        for(int j = 1; j < cols; j++) {
            for(int node = 0; node < n; node++) {
                if(ancestorTable[node][j-1] != -1) {
                    ancestorTable[node][j] = ancestorTable[ ancestorTable[node][j-1] ][j-1];
                }
            }
        }
    }

    //get LCA using Binary Lifting
    int getLCA(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for(int j = 0; j < cols; j++) {
            if(diff & (1 << j)) {
                u = ancestorTable[u][j];
            }
        }

        if(u == v) 
            return u;

        for(int j = cols - 1; j >= 0; j--) {
            if(ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this -> n = n;
        for(auto e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        eulerTour.assign(2*n, 0);

        // assuming root -> 0
        timer = 0;
        cols = log2(n)+1;
        ancestorTable.assign(n, vector<int>(cols, -1));
        DFS(0, -1, 0, s);

        // building segment tree for eulerTour 
        int N = 2*n;
        segmentTree.resize(4*N, 0);
        buildSegmentTree(0, 0, N-1);

        buildAncestorTable();

        vector<bool> result;

        for(auto &q : queries){
            stringstream ss(q);
            string type;
            ss >> type;

            if(type == "update"){
                int node;
                char c;
                ss >> node >> c;

                int charValue = 1 << (c - 'a');
                s[node] = c;
                updateSegmentTree(tin[node], charValue, 0, 0, 2*n-1);
                updateSegmentTree(tout[node], charValue, 0, 0, 2*n-1);
            }
            else{
                int u, v;
                ss >> u >> v;
                
                int lcaNode = getLCA(u, v);
                char ch = s[lcaNode];
                int chValue = 1 << (ch - 'a');
                int mask = searchSegmentTree(0, tin[u], 0, 0, 2*n-1) ^ 
                            searchSegmentTree(0, tin[v], 0, 0, 2*n-1) ^ chValue;
                
                result.push_back((mask & (mask-1)) == 0);

            }
        }

        return result;
    }
};
