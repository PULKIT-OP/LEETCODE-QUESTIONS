// Question Link: https://leetcode.com/problems/partition-string/description/


// METHOD 1: First Instinct Method

class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.length();

        unordered_map<string, bool> seen;
        string newSegment = "";
        vector<string> result;
        for(int i = 0; i < n; i++){
            newSegment.push_back(s[i]);
            if(!seen[newSegment]){
                result.push_back(newSegment);
                seen[newSegment] = true;
                newSegment = "";
            }
        }

        return result;
    }
};

// METHOD 2: Optimized 

class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.length();

        unordered_set<string> seen;
        string newSegment = "";
        vector<string> result;
        for(int i = 0; i < n; i++){
            newSegment.push_back(s[i]);
            if(!seen.contains(newSegment)){
                seen.insert(newSegment);
                result.push_back(newSegment);
                newSegment = "";
            }
        }

        return result;
    }
};


// METHOD 3: Insertion and checking in one step

class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.length();

        set<string> seen;
        string newSegment = "";
        vector<string> result;
        for(int i = 0; i < n; i++){
            newSegment.push_back(s[i]);
            if(seen.insert(newSegment).second){
                result.push_back(newSegment);
                newSegment = "";
            }
        }

        return result;
    }
};
