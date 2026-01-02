// Question Link: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// This question is a Applicaton of KOSARAJU's Algorithm.
// In this Question it is asked to get the number of strongly connected elements means ---> if you start from a node of that element or group of nodes connected together then you can visited each element and from each node you can visit all other nodes of that element
// To achieve this we will be using KOSARAJU's Algo :
// Firstly we will get the topological sorted order of the graph in a stack
// Then we will make a new adj list in which we will reverse the mapping of nodes. If we have u ---> v then we will reverse it to v ---> u
// And at last we will apply DFS of each node in topological order from stack, after every DFS ends we will increment the count of elements 
// At the end we will get the number of strongly connected elements in our count variable.


class Solution {
  public:

// DFS to get the final answer 
    void DFS2(int u, vector<vector<int>> &adj, vector<bool> &visited){
        visited[u] = true;
        
        for(auto &v : adj[u]){
            if(!visited[v]){
                DFS2(v, adj, visited);
            }
        }
    }

// DFS to fill up the stack in topological order
    void DFS1(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st){
        visited[u] = true;
        
        for(auto &v : adj[u]){
            if(!visited[v]){
                DFS1(v, adj, visited, st);
            }
        }
        
        st.push(u);
    }

// Main Quesion Funciton
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();

      // STEP 1: FILL UP THE STACK
        vector<bool> visited(n, false);
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                DFS1(i, adj, visited, st);
            }
        }

      // STEP 2: MAKE THE REVERSE ADJ LIST AND FILL IT UP
        vector<vector<int>> ad(n);
        
        for(int i = 0; i < n; i++){
            vector<int> v = adj[i];
            for(int j = 0; j < v.size(); j++){
                ad[v[j]].push_back(i);
            }
        }

      // STEP 3: GET THE NUMBER OF STRONGLY CONNECTED ELEMENTS
        int count = 0;
        vector<bool> vis(n, false);
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                DFS2(node, ad, vis);
                count++;
            }
        }
        
        return count;
    }
};
