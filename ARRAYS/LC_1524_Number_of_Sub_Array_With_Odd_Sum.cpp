// Question Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum


// METHOD 1: 

class Solution {
public:
    int n;
    int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        n = arr.size();

        int count = 0;
        int odd = 0;
        int even = 1;
        int prefixSum = 0;
        for(int i = 0; i < n; i++){
            prefixSum += arr[i];
            if(prefixSum%2 == 0){
                count = (count + odd)%MOD;
                even++;
            }
            else{
                count = (count + even)%MOD;
                odd++;
            }
        }

        return count;
    }
};
