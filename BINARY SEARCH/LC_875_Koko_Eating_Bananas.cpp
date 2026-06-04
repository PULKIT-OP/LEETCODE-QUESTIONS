// Question Link: https://leetcode.com/problems/koko-eating-bananas/


// METHOD 1: Binary search 

class Solution {
public:

// Finding total how much hours it will take koko to eat all the bananas if he eats at speed of mid/hr
    double findHour(int mid, int n, vector<int> &piles){
        double ans = 0;
        for(int i = 0; i < n; i++){
            ans = ans + ceil((double)piles[i]/mid);
        }

        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int k = INT_MAX;    // Minimum banana that koko required to eat in an hour
        while(low <= high){
            int mid = low + (high - low)/2;  // banana that koko might eat in an hour
            double reqHour = findHour(mid, n, piles);    // if koko eat mid bananan each hour then she will take reqHour hours to eat all
            if(reqHour <= h){    // if reqHours are less than h then it is acceptable and then try to find low values
                k = min(mid, k);
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return k;
    }
};



// METHOD 2: Binary Search ----->  return low

class Solution {
public:
    double findHour(int mid, int n, vector<int> &piles){
        double ans = 0;
        for(int i = 0; i < n; i++){
            ans = ans + ceil((double)piles[i]/mid);
        }

        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            int mid = low + (high - low)/2;
            double reqHour = findHour(mid, n, piles);
            if(reqHour <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};
