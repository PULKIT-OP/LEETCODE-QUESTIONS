// Question Link: https://leetcode.com/problems/redundant-connection-ii/description/


// METHOD 1: Using DSU
// there are only three cases possible, 1. we have only cycle in the graph, 2. we have 2 parents of atmost 1 node or at last 3. we have 1 node which have 2 parents + cycle in the graph.
// We just need to find out which case is there in the question and proceed accordingly
// 1. if only cycle is there then this question is reduced to part 1 of this question
// 2. if we have 2 parents and 2 parents + cycle type of cases then by observation we can find that we have two options of edges that can be removed, so we just need to check by removing which edge no complication is there 

class Solution {
public:
    int n;
    int find(int x, vector<int> &parent){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x], parent);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        n = edges.size();

        vector<int> parent(n+1, 0);
        vector<int> candidate_a, candidate_b;

        for(auto e : edges){
            int p = e[0];
            int c = e[1];

          // if parent is not 0 then it means you have seen this node before
            if(parent[c] != 0){
              // one edge is this current edge and other edge is bw the child node and its parent, because this is already visited, so we got our two options of edges out which one is our answer
                candidate_b = e;
                candidate_a = {parent[c], c}; 
            }
            else{
              // if parent is not there then mark its parent 
                parent[c] = p;
            }
        }

      // Now normal parent marking 
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

      // Now we are checking without removing edge b can we get our answer like with edge a is it possible
        for(auto e : edges){
          // if we get edge b -->  continue
            if(e == candidate_b){
                continue;
            }

          // find parent of both the nodes
            int a = find(e[0], parent);
            int b = find(e[1], parent);

          // if parent of both the nodes are same means a and b are already connected which current edge is trying to connect ( 2 parents case )
            if(a == b){
              // if you find edge a is non empty, then this is the case 3 cycle present and two parents are there
                if(candidate_a.size() > 0){
                  // then this edge a is your answer, you can remove this edge
                    return candidate_a;
                }
                else{
                  // but if you find no two parents then its case 2 which is only two parents then return current edge e, this edge is unnecessary bcoz its trying to connect nodes which are already connected
                    return e;
                }
            }
              // and if both a and b are not equal then union them
            else{
                parent[a] = b;
            }
        }

      // we started with assuming candidate_b is not answer and we tried to get the ans without candidate_b, but we didnot foudn then candidate_b is our answer, this edge is unnecessary

        return candidate_b;

    }
};
