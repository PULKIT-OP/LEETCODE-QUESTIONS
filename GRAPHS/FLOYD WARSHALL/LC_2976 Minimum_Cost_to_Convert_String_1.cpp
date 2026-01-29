// Question Link: https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/


// MEHTOD 1: USING FLOYD-WARSHALL ALGORITHM

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.length();

      // To store minimum Disttance from each node to every other node 
        vector<vector<long long>> dist(26, vector<long long>(26, INT_MAX));

      // Storing initial given cost to reach changed node from original node
        for(int i = 0; i < ori; i++){
            dist[original[i] - 'a'][changed[i] - 'a'] = min(dist[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
        }

      // NOW CLASSIC FLOYD-WARSHALL ALGO 
        for(int via = 0; via < 26; via++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(dist[i][j] > dist[i][via] + dist[via][j] && dist[i][via] != INT_MAX && dist[via][j] != INT_MAX){
                        dist[i][j] = dist[i][via] + dist[via][j];
                    }
                }
            }
        }

      // Finding final cost to change source string to target string, if not possible return -1 fataak se
        long long total_cost = 0;
        for(int i = 0; i < n; i++){
            if(source[i] != target[i]){
                int cost = dist[source[i]-'a'][target[i]-'a'];
                if(cost == INT_MAX){
                    return -1;
                }
                total_cost += cost;
            }
        }

        return total_cost;
    }
};



// METHOD 2: USING DIJKSTRA ALGORITHM

class Solution {
public:
    void solve(char source, vector<vector<long long>> &minDist, unordered_map<char, vector<pair<int, char>>> &adj){
      // making priority_queue
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;  // cost, neigh
        pq.push({0, source});

        while(!pq.empty()){
            int c = pq.top().first;
            char node = pq.top().second;
            pq.pop();

            for(auto &e : adj[node]){
                int c_ = e.first;
                char neigh = e.second;

              // checking minimum distace from source to neighbour   -->  because we are running dijsktra for each character so we will fill minDist for each character
              // simply bhai hum har ek character se har ek character tk ka minimum distance find out kr rahe hain ---> to abhi baari source ki hai isiliye source se neighbour tk ka store kr rahe hain
              // abhi bhi nahi smjha to DSA chod de
                if(minDist[source-'a'][neigh-'a'] > c + c_){
                    minDist[source-'a'][neigh-'a'] = c + c_;
                    pq.push({c+c_, neigh});
                }
            }
        }

        return;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.length();
        int or_len = original.size();

        // making adj list ---> "char --> {cost, neighbour}"
        unordered_map<char, vector<pair<int, char>>> adj;
        for(int i = 0; i < or_len; i++){
            adj[original[i]].push_back({cost[i], changed[i]});
        }

      // To store minimum distance from one node to other ---> initially infinity
        vector<vector<long long>> minDist(26, vector<long long>(26, INT_MAX)); 
      // Storing if the character is iterated with dijkstra ---> simply ye store kr rahe hai ki koi character pr dijsktra mar diya ya nahi taki same character pr repeated dijsktra na maarein
        vector<bool> done(26, false);

      // Now run dijsktra on each character of source 
        for(int i = 0; i < n; i++){
            char ch = source[i];
            if(!done[ch-'a']){
                solve(ch, minDist, adj);
                done[ch-'a'] = true;
            }
        }

      // storing final cost of changing string
        long long total_cost = 0;
        for(int i = 0; i < n; i++){
            if(source[i] == target[i]){
                continue;
            }
            else{
              // If changing cost if infinity ---> means we cant change the string to simply return -1
                if(minDist[source[i]-'a'][target[i]-'a'] == INT_MAX){
                    return -1;
                }
              // otherwise add cost of change in total cost
                total_cost += minDist[source[i]-'a'][target[i]-'a'];
            }
        }

        return total_cost;
    }
};
