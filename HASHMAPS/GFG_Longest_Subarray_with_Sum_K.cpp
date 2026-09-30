// Question Link: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

// METHOD 1: BruteForce Method

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
 
        int result = 0;
        
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum = sum + arr[j];
                if(sum == k){
                    result = max(result, j-i+1);
                }
            }
        }
        
        return result;
    }
};

// METHOD 2: Using HashMap
// check if sum if zero ---> then update the size as i+1
// otherwise if you have seen sum-k before then from that index till current index total sum is K so try update result 
// if you hvae not seen this sum before than mark it seen on that idx and move forward

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        unordered_map<int, int> mp;
        int sum = 0;
        int result = 0;
        
        for(int i = 0; i < n; i++){
            sum = sum + arr[i];
            if(sum == k){
                result = i+1;
            }
            else{
                if(mp.find(sum-k) != mp.end()){
                    int idx = mp[sum-k];
                    result = max(result, i - idx);
                }
                if(mp.find(sum) == mp.end()){
                    mp[sum] = i;
                }
            }
        }
        
        return result;
    }
};
