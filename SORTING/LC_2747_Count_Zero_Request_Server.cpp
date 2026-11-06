// Question Link: https://leetcode.com/problems/count-zero-request-servers/description


// METHOD 1: Using Sorting
// Not a great solution but works
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        auto lambda = [&](vector<int> v1, vector<int> v2){
            return v1[1] < v2[1];
        };
        sort(logs.begin(), logs.end(), lambda);    // sort logs over time

        vector<pair<int, int>> query;    // storing query idx so that after sorting we know its original position
        int i = 0;
        int qidx = queries.size();
        int lidx = logs.size();
        for(int &q : queries){
            query.push_back({q, i});
            i++;
        }
        sort(query.begin(), query.end());  // sort queries over time

        vector<int> arr(qidx);  // to store final answer
        unordered_map<int, int> mpp;  // to store the servers present in a time frame window
        i = 0; 
        int j = 0;
      // iterating over each query
        for(auto &q : query){
            int prev = q.first - x;
            int idx = q.second;  // actual position of this query 
          // if log timing is smaller than the time given then store it and move forward
            while(j < lidx && logs[j][1] <= q.first){
                mpp[logs[j][0]]++;
                j++;
            }
          // if the stored time is less the lower limit then remove it
            while(i < j && logs[i][1] < prev){
                int id = logs[i][0];
                mpp[id]--;
                i++;
                if(mpp[id] == 0){
                    mpp.erase(id);
                }
            }

          // now whatever we have in the map are our final servers that were operating in the given time frame of prev time and given time
          // store it in the actual index
            arr[idx] = n - mpp.size();
        }

      // At last return result;
        return arr;
    }
};
