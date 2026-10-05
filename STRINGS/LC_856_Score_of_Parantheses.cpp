// Question Link: https://leetcode.com/problems/score-of-parentheses/description


// METHOD 1: Using Iterative method 

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();

        int score = 0;
        vector<int> vec;
      
        for(int i = 0; i < n; i++){
          // If you are getting fresh opening bracket just store the previous found score and start new
            if(s[i] == '('){
                vec.push_back(score);
                score = 0;
            }
            else{
              // otherwise check if at previous index you had opening bracket ---> It means its the basic entity so increment 1 in your previous found score
                if(s[i-1] == '('){
                    score = vec.back() + 1;
                }
                  // or if previosly you had closing bracket as well then its a nested bracket, you double the current score you have found and add it to previously stored answer
                else if(s[i-1] == ')'){
                    score = vec.back() + (score * 2);
                }
                vec.pop_back();  // at last just remove the previously found score so that new score can be stored
            }
        }

        return score;
    }
};


// METHOD 2: Space optimization

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();

        int depth = 0;  // to get the depth info in nested brackets 
        int score = 0; // to store the score 

        for(int i = 0; i < n; i++){
          // if you find opening bracket then incremnet depth
            if(s[i] == '('){
                depth++;
            }
            else{
              // otherise checck if you had opening bracket previously, if yes then incremnt the score with the dpeht score
                if(s[i-1] == '('){
                    score += (1 << (depth-1));
                }
                depth--;  // and decrese depth continiously if you find closing brackets
            }
        }

        return score;   // at last return score
    }
};
