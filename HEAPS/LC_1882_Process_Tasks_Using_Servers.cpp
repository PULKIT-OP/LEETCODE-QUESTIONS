// Question Link: https://leetcode.com/problems/process-tasks-using-servers/description


// METHOD 1:

class Solution {
public:
    int s;
    int t;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        s = servers.size();
        t = tasks.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> availableServers; // weight, idx
        for(int i = 0; i < s; i++){
            availableServers.push({servers[i], i});
        }

        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> unavailableServers; // outtime, weight, serverIdx
        vector<int> result(t);

        for(int i = 0; i < t; i++){
            while(!unavailableServers.empty() && get<0>(unavailableServers.top()) <= i){
                auto [time, wt, idx] = unavailableServers.top();
                unavailableServers.pop();
                availableServers.push({wt, idx});
            }
            if(availableServers.empty()){
                auto [time, wt, idx] = unavailableServers.top();
                unavailableServers.pop();
                result[i] = idx;
                unavailableServers.push({time+tasks[i], wt, idx});
            }
            else{
                auto [wt, idx] = availableServers.top();
                availableServers.pop();
                result[i] = idx;
                unavailableServers.push({i + tasks[i], wt, idx});
            }
        }

        return result;
    }
};
