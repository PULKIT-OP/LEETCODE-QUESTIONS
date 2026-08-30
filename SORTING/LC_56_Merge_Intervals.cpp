// Question Link: https://leetcode.com/problems/merge-intervals/description/


// METHOD 1: 

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;

        int sTime = intervals[0][0];
        int eTime = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= eTime){
                eTime = max(eTime, intervals[i][1]);
            }
            else{
                result.push_back({sTime, eTime});
                sTime = intervals[i][0];
                eTime = intervals[i][1];
            }
        }

        result.push_back({sTime, eTime});

        return result;
    }
};
