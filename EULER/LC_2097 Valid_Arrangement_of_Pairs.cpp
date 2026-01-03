// Question Link: 

// MEHTOD 1: USING HIERHOLZER's ALGORITHM (DFS with stack):


class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;

        unordered_map<int, int> inDegree;
        unordered_map<int, int> outDegree;
        for(auto &e : pairs){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            inDegree[v]++;
            outDegree[u]++;
        }

        int start = pairs[0][0];
        for(auto &it : adj){
            int node = it.first;
            if(outDegree[node] - inDegree[node] == 1){
                start = node;
                break;
            }
        }

        unordered_map<int, bool> visited;
        vector<int> path;
        for(auto it : inDegree){
            visited[it.first] = false;
        }
        stack<int> st;
        st.push(start);

        while(!st.empty()){
            int curr = st.top();

            if(!adj[curr].empty()){
                st.push(adj[curr].back());
                adj[curr].pop_back();
            }
            else{
                path.push_back(curr);
                st.pop();
            }
        }
        reverse(path.begin(), path.end());
        vector<vector<int>> result;

        for(int i = 0; i < path.size(); i++){
            if(i+1 < path.size()){
                result.push_back({path[i], path[i+1]});
            }
        }


        return result;
    }
};

// METHOD 2: USING HIERHOLZER's ALGORITHM (DFS with recursion):


class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> path;

    void dfs(int u) {
        while (!adj[u].empty()) {
            int v = adj[u].back();
            adj[u].pop_back();   // consume edge
            dfs(v);
        }
        path.push_back(u);      // post-order
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,int> inDegree, outDegree;

        for (auto &e : pairs) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

        int start = pairs[0][0];
        for (auto &it : adj) {
            int node = it.first;
            if (outDegree[node] - inDegree[node] == 1) {
                start = node;
                break;
            }
        }

        dfs(start);
        reverse(path.begin(), path.end());

        vector<vector<int>> result;
        for (int i = 0; i + 1 < path.size(); i++) {
            result.push_back({path[i], path[i + 1]});
        }

        return result;
    }
};
