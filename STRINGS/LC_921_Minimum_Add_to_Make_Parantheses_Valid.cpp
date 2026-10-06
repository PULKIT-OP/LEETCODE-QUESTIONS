// Question Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description


// METHOD 1: Using one loop ----> Most optimized as of now, AFAIK

class Solution {
public:
    int n;
    int minAddToMakeValid(string s) {
        n = s.length();

        int extraOpen = 0;  // to store extra open brackets
        int extraClose = 0;  // to store extra close brackets
  
        for(int i = 0; i < n; i++){
            if(s[i] == ')'){
              // if its close then it can balance extraOpen brackets so decrease extraOpen brackets
                extraOpen--;
              // And check if it acutally balances or it more than open brackets, if its more than open then make open brakcets zero and increment extraClose brakcets
                if(extraOpen < 0){
                    extraOpen = 0;
                    extraClose++;
                }
            }
            else{
              // If its open bracket then increment extraOpen 
                extraOpen++;
            }
        }
      
        // At last return extra oepn + extra close
        return extraOpen + extraClose;
    }
};
