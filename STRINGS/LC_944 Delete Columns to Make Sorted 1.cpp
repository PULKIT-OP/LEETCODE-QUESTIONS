// Question Link: https://leetcode.com/problems/delete-columns-to-make-sorted/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int n2 = strs[0].length();
        int count = 0;
        for(int col = 0; col < n2; col++){
            for(int row = 0; row < n-1; row++){
                if(strs[row][col] > strs[row+1][col]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
