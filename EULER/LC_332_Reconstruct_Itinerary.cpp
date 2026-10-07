// QUESTION LINK: https://leetcode.com/problems/reconstruct-itinerary/description/


// METHOD 1: DFS + BACKTRACKING ----> TLE Not recommened if the testcaeses are hard

class Solution {
public:
    int n;
    bool DFS(string src, vector<string> &path, vector<string> &result, unordered_map<string, vector<string>> &adj){
        path.push_back(src);
        if(path.size() == n+1){
            result = path;
            return true;
        }

        vector<string> &neigh = adj[src];

        for(int i = 0; i < neigh.size(); i++){
            string toArp = neigh[i];
            neigh.erase(neigh.begin() + i);

            if(DFS(toArp, path, result, adj) == true){
                return true;
            }

            neigh.insert(neigh.begin() + i, toArp);
        }

        path.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();

        unordered_map<string, vector<string>> adj;
        for(auto e : tickets){
            string u = e[0];
            string v = e[1];
            
            adj[u].push_back(v);
        }

        for(auto &e : adj){
            sort(e.second.begin(), e.second.end());
        }

        vector<string> path;
        vector<string> result;
        DFS("JFK", path, result, adj);

        return result;
    }
};



// METHOD 2: Using EULERS PATH METHOD

class Solution {
public:
    int n;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();
        
        unordered_map<string, vector<string>> adj;
        for(auto e : tickets){
            string u = e[0];
            string v = e[1];
            
            adj[u].push_back(v);
        }

        auto lambda = [&](string s1, string s2){
            return s1 > s2;
        };

        for(auto &e : adj){
            sort(e.second.begin(), e.second.end(), lambda);
        }

        vector<string> result;

        stack<string> st;
        st.push("JFK");

        while(!st.empty()){
            string curr = st.top();
            if(!adj[curr].empty()){
                string neigh = adj[curr].back();
                adj[curr].pop_back();
                st.push(neigh);
            }
            else{
                result.push_back(curr);
                st.pop();
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
