// Question Link: https://leetcode.com/problems/reverse-degree-of-a-string/description

// METHOD 1: Brute Force method 

class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        unordered_map<char, int> alpha = { 
            {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}, 
            {'h', 8}, {'i', 9}, {'j', 10}, {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, 
            {'o', 15}, {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20}, {'u', 21}, 
            {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25}, {'z', 26} 
        };

        int final_ans = 0;
        for(int i = 0; i < n; i++){
            int newIdx = 26 - alpha[s[i]] + 1;
            final_ans += (newIdx * (i+1));
        }

        return final_ans;
    }
};


// METHOD 2: Optimized method 

class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();

        int final_ans = 0;
        for(int i = 0; i < n; i++){
            int newIdx = 'z' - s[i] + 1;
            final_ans += (newIdx * (i+1));
        }

        return final_ans;
    }
};
