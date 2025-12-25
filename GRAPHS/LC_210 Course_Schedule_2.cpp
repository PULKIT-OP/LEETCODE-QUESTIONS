// Question Link: https://leetcode.com/problems/course-schedule-ii/description/

// METHOD 1: KAHN's ALGORITHM (BFS)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses, 0);
        for(auto &vec : prerequisites){
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u);
        }

        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            inDeg[u]++;
        }

        queue<int> que;
        vector<int> result;
        for(int i = 0; i < numCourses; i++){
            if(inDeg[i] == 0){
                que.push(i);
            }
        }
        
        int count = 0;

        while(!que.empty()){
            int node = que.front();
            que.pop();
            result.push_back(node);
            count++;

            for(auto &v : adj[node]){
                inDeg[v]--;

                if(inDeg[v] == 0){
                    que.push(v);
                }
            }
        }

        if(count != numCourses){
            return {};
        }

        return result;

    }
};


// METHOD 2: USING BFS  ------> Cycle detection using inRecursion logic + topological sorting using stack logic ----> this complete package gives us the required result


class Solution {
public:
    bool cycle = false;
    void DFS(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inRecursion, stack<int> &st){
        visited[u] = true;
        inRecursion[u] = true;

        for(auto &v : adj[u]){
          // if the node is never visited then it is safe to go deeper
            if(!visited[v]){
                DFS(v, adj, visited, inRecursion, st);
            }
          // but if the node is already visited then check is it in the same recursion stack if yes then it is definetly a loop end this and return.
            else if(inRecursion[v]){
                cycle = true;
                return;
            }
        }
      // At last mark inrecursion false and push node in stack.
        inRecursion[u] = false;
        st.push(u);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &vec : prerequisites){
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        stack<int> st;

        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                DFS(i, adj, visited, inRecursion, st);
            }
        }
      // if you have found loop in graph it means you cant complete all courses then in this case return empty array
        if(cycle == true){
            return {};
        }

      // if no loop then push the elements of stack in array.
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
      
        return result;
    }
};
