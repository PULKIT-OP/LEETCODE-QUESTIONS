// Question Link: https://leetcode.com/problems/top-k-frequent-words/description/

// METHOD 1: Using vector and custom comparator Using heaps

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();

        unordered_map<string, int> mp;

        for(int i = 0; i < n; i++){
            mp[words[i]]++;
        }

        vector<pair<string, int>> wordFreq;
        for(auto &e : mp){
            wordFreq.push_back({e.first, e.second});
        }

        auto lambda = [&](pair<string, int> p1, pair<string, int> p2){
            if(p1.second != p2.second){
                return p1.second > p2.second;
            }
            return p1.first < p2.first;
        };

        sort(wordFreq.begin(), wordFreq.end(), lambda);

        vector<string> ans;

        for(int i = 0; i < k; i++){
            ans.push_back(wordFreq[i].first);
        }

        return ans;

    }
};
