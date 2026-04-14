// Question Link: https://leetcode.com/problems/clone-graph/description/

// METHOD 1: Using DFS

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    void DFS(Node *node, Node *clone){
      // traverse neighbors
        for(Node *n : node -> neighbors){
          // if cant find any clone node in map for the current node then make one
            if(mp.find(n) == mp.end()){
                Node *cl = new Node(n -> val);
              // map the clone node with curent node 
                mp[n] = cl;
              // now push the clone node you made in actual clone node's neighbour
                clone -> neighbors.push_back(cl);
                DFS(n, cl); // then call dfs for this pair of node and its clone
            }
            else{
              // if clone if already present then just push it in clone node
                clone -> neighbors.push_back(mp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        mp.clear();
        // clone of given node
        Node* clone = new Node(node->val);

        // Now store its neighbours, recursively their nieghbours
        /*
            If the same node reappears than take the cloned node for it, for
           that we need to store node and its clone in a map
        */
        mp[node] = clone;
      // call dfs for this node and its clone node 
        DFS(node, clone);

        return clone;
    }
};


// METHOD 2: Using BFS

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        mp.clear();
        // clone of given node
        Node* clone = new Node(node->val);

        // Now store its neighbours, recursively their nieghbours --> with bfs and dfs both
        /*
            If the same node reappears than take the cloned node for it, for
           that we need to store node and its clone in a map
        */
        mp[node] = clone;

        queue<Node*> que;
        que.push(node); // pushing initial node to start

        while(!que.empty()){
            Node *u = que.front();
            Node *clone_node = mp[u];
            que.pop();
              // exploring neighbors
            for(Node *n : u -> neighbors){
              // if you find clone not made then make one
                if(mp.find(n) == mp.end()){
                    Node *copy = new Node(n -> val);
                  // add it in map
                    mp[n] = copy;
                  // as this node(n) is a neighbor node then its clone node will be neighbors for clone_node, so puch in it
                    clone_node -> neighbors.push_back(copy);
                    que.push(n); // then push this node in que for further iteration
                }
                else{
                  // if you find clone node already been made then just push that clone node in this clone_node as both will be neighbors
                    clone_node -> neighbors.push_back(mp[n]);
                }
            }
        }

      // at last return the clone node you made first
        return clone;
    }
};
