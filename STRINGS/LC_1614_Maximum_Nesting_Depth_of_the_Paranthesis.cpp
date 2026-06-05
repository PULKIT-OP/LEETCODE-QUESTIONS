// Question Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

// METHOD 1: BruteFroce -----> Just iterate through the string when found openeing bracket increase the count and when found closing bracket decrease count, after each iteration check for the max count you had and update if available
class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();

        int ans = INT_MIN;
        int depth = 0;
        int i = 0;
        while(i < n){
            if(s[i] == '('){
                depth++;
            }
            else if(s[i] == ')'){
                depth--;
            }
            ans = max(ans, depth);
            i++;
        }

        return ans;
    }
};
