// Question Link: https://leetcode.com/problems/words-within-two-edits-of-dictionary/

// METHOD 1: We actually dont need to change the words and match with the dictionary, we just need to check if the words differ by 2 or less then we will count it otherwise they are of no use.
// Just a bruteforce solution nothing special

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for(auto &q : queries){
            for(auto &d : dictionary){
                int count = 0;
                for(int i = 0; i < q.length(); i++){
                    if(q[i] != d[i]){
                        count++;
                    }
                    if(count > 2){
                        break;
                    }
                }
                if(count <= 2){
                    result.push_back(q);
                    break;
                }
            }
        }

        return result;
    }
};
