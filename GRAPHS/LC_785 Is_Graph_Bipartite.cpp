// Question Link: https://leetcode.com/problems/is-graph-bipartite/description/

//Bipartite Graph: A graph whose adjacent nodes cant be of same color, all adjacent nodes should of different color. in simple terms all nodes can be divided in two groups.
// Bipartite type question Identification: Question will ask to group the graph in two parts or distribute in two parts.


// METHOD 1: USING DFS
class Solution {
public:
    bool DFS(int u, vector<vector<int>>& adj, vector<int> &color, int currColor){

      // mark visited or coloured
        color[u] = currColor;
      // Iterating neighbours 
        for(auto &v : adj[u]){
          //if color of neighbour == current node color then it is not bipartite return false.
            if(color[v] == currColor){
                return false;
            }
          // check if it is visited of not 
            if(color[v] == -1){
              // if not visited then find out its color which we will be using to color it
                int colorOfV = 1 - currColor;
                // then dfs on this node with its color if this gives us false means its not bipartite so return false.
                if(DFS(v, adj, color, colorOfV) == false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
      // here instead of visited we use color array which can be used for two purposes, first it will store the color of nodes and other is to check if the node if visited.
        vector<int> color(graph.size(), -1);
      // Normal iteration like DFS
        for(int i = 0; i < graph.size(); i++){
          // check if the node is visited or coloured
            if(color[i] == -1){
              // if not visited yet then check if it is bipartite with dfs
                if(DFS(i, graph, color, 1) == false){
                    return false;
                }
            }
        }

        return true;
    }
};

// METHOD 2: USING BFS

class Solution {
public:
    bool BFS(int u, vector<vector<int>>& adj, vector<int> &color, int currColor){
      // same as bfs
        color[u] = currColor;
        queue<int> que;
        que.push(u);

        while(!que.empty()){
            int node = que.front();
            que.pop();
          // check neighbours 
            for(auto &v : adj[node]){
              // if v has same color as current node then it is not bipartite so return false
                if(color[v] == color[node]){
                    return false;
                }
                  // if it is not visited yet then color it with the oposite of current node color then push it in queue for further iteration
                else if(color[v] == -1){
                    color[v] = 1 - color[node];
                    que.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1){
                if(BFS(i, graph, color, 1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
