// Question Link: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/

// BINARY LIFTING THEORY
/*
we use Binary Lifting method when we have to go up in a tree from bottom node
here we jump from bottom nodes to its upward or ancestor nodes
We only jump in powers of 2
If we want to go to 1st ancestor then we will jump 2^0 th node
if we wnat to go to 57th ancestor then we will jump to 2^56 nodes

To do this we dont jump in real time instead of that we store all the jumping data in a grid before hand and we use that table to find out answer on the go
we know if we are on root node then its parent is no one or there is no ancestor so it will marked as -1
if we have total of 5 nodes and I want to find out 7th ancestor of all the nodes then its not possible so it will be -1 for each node --> just keep this in mind for future

While filling the table we will start filling from the root node or top node so by the time we reach bottom node or any other node we dont know 
for that we find out what is the node which is at half way then from that we can find out its half way ancestor we wanted to find out
if you have to find out what is the jth ancestor of current node --> break it as j-1 and j-1 --> here is j is 2^j so j-1 is its half


*/

// METHOD 1: Using Binary Lifting Method 

class TreeAncestor {
    vector<vector<int>> ancestor;
    int rows, cols;
public:
    TreeAncestor(int n, vector<int>& parent) {
        rows = n;
        cols = log2(n) + 1;
        ancestor.resize(rows, vector<int> (cols, -1));

        for(int node = 0; node < n; node++){
            ancestor[node][0] = parent[node];
        }

        for(int j = 1; j < cols; j++){
            for(int node = 0; node < n; node++){
                if(ancestor[node][j-1] != -1){
                    ancestor[node][j] = ancestor[ancestor[node][j-1]][j-1];
                }
            }
        }
        
    }
    
    int getKthAncestor(int node, int k) {
        for(int j = 0; j < cols; j++){
            // if jth bit is set so we can use 2^j jump
            if(k & (1 << j)){
                node = ancestor[node][j];
            }
            if(node == -1){
                return -1;
            }
        }

        return node;
    }
};
