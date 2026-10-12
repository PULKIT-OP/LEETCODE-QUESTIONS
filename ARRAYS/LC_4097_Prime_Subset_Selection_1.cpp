// Question Link: https://leetcode.com/problems/prime-subset-selection-i/description/

// ITS MY QUESTION --> I CONTRIBUTED IT IN LEETCODE

// METHOD 1:

class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool> isPrime(n+1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i*i <= n; i++){
            for(int j = 2; i*j <= n; j++){
                if(isPrime[i] == true){
                    isPrime[i*j] = false;
                }
            }
        }

        vector<int> result;
        long long sum = 0;

        for(int i = 2; i <= n; i++){
            if(isPrime[i]){
                if(sum + i <= s){
                    sum += i;
                    result.push_back(i);
                }
                else{
                    break;
                }
            }
        }

        return result;
    }
};
