// Question Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/


// METHOD 1: USING LINEAR SEARCH 

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        for(int i = 0; i < letters.size(); i++){
            if(letters[i] > target){
                ans = letters[i];
                break;
            }
        }

        return ans;
    }
};


// METHOD 2: USING BINARY SEARCH

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        int l = 0;
        int r = letters.size()-1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(letters[mid] > target){
                r = mid - 1;
                ans = letters[mid];
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};
