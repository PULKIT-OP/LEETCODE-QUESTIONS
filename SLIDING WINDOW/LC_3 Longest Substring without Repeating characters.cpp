// Here we are using sliding window approach 

int lengthOfLongestSubstring(string s) {
    int n = s.length();

    int i = 0;
    int j = 0;
    int maxi = 0;
    vector<int> v(255, -1);

    while(j < n){
        if(v[s[j]] != -1){
            if(v[s[j]] >= i){
                i = v[s[j]] + 1;
            }
        }
        int len = j-i+1;
        maxi = max(maxi, len);
        v[s[j]] = j;
        j++;
    }
    return maxi;
}

// Clean and readable method

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int i = 0; 
        int j = 0;
        int ans = 0;
        unordered_map<char, int> seen;
        while(j < n){
            // if you have seen current element before then remove it from current set
            while(seen[s[j]] > 0){
                seen[s[i]]--;
                i++;
            }
            // mark current element seen and store the max length of array we have found till now
            seen[s[j]]++;
            ans = max(ans, j-i+1);
            j++;    // increment j
        }

        return ans;
    }
};
