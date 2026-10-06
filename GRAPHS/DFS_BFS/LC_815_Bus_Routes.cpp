// Question Link: https://leetcode.com/problems/bus-routes/description/

// METHOD 1: Using BFS

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();

        if(source == target){
            return 0;
        }

        unordered_map<int, vector<int>> bus;  // To store the buses that a stops have, like which buses crosses this stop
        for(int i = 0; i < n; i++){
            for(auto e : routes[i]){
                bus[e].push_back(i);
            }
        }

      // Normal BFS
        queue<int> q;
        vector<bool> visited(n, false);  // to store which buses we have visited
        for(auto e : bus[source]){
          // starting with the buses that goes to source stop and mark them visited
            q.push(e);
            visited[e] = true;
        }

        int steps = 0;  // to store no. of buses changes
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();

              // getting which stops current bus(node) goes to
                for(auto stop : routes[node]){
                  // if it goes to target then we got our answer
                    if(stop == target){
                        return steps+1;
                    }
                  // then checking which buses comes at this stop so that we can use that bus to reach target
                    for(auto nextBus : bus[stop]){
                      // if we have not visited this bus before then use this bus 
                        if(!visited[nextBus]){
                            q.push(nextBus);
                            visited[nextBus] = true;
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
