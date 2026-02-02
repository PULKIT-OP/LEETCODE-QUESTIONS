// Question Link: 

// METHOD 1: RECURSION ---> TLE

class Solution {
public:
    int m;
    int n;
    bool solve(int i, int j, string &s, string &p){
      // if you traversed through all the string and found no false then return true
        if(i < 0 && j < 0){
            return true;
        }
      // if pattern string ends first but s string doesnt then return false
        if(i >= 0 && j < 0){
            return false;
        }
      // if s string ends first but pattern string doesnt then check ---> if remaining string has only '*', if you find any other character other than this then instantly return false
        if(i < 0 && j >= 0){
            for(int k = 0; k <= j; k++){
                if(p[k] != '*'){
                    return false;
                }
            }
          // if you found no false return true ---> means it has only '*'
            return true;
        }
      // if both characters are equal or you find '?' in pattern string then call function for next iteration
        if(s[i] == p[j] || p[j] == '?'){
            return solve(i-1, j-1, s, p);
        }
      // otherwise if you find a '*' then check for two cases
        else if(p[j] == '*'){
          // assume this star as empty string  and  second is assume this star as one character
            bool emp = solve(i, j-1, s, p);
            bool take = solve(i-1, j, s, p);
            return emp || take;
        }

        return false;
    }
    bool isMatch(string s, string p) {
        m = s.length();
        n = p.length();

        return solve(m-1, n-1, s, p);
    }
};
