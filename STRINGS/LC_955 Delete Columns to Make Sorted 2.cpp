// Question Link: https://leetcode.com/problems/delete-columns-to-make-sorted-ii/description/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int r = strs.size();
        int c = strs[0].size();
        int deletion = 0;
        vector<bool> alreadySorted(r - 1, false);

        for(int i = 0; i < c; i++){
            bool deleted = false;
            for(int j = 0; j < r-1; j++){
                if(!alreadySorted[j] && strs[j][i] > strs[j+1][i]){
                    deletion++;
                    deleted = true;
                    break;
                }
            }

            if(deleted){
                continue;
            }

            for(int row = 0; row < r-1; row++){
                alreadySorted[row] = alreadySorted[row] | strs[row][i] < strs[row+1][i];
            }
        }
        return deletion;
    }
};
