// Question Link: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1


// METHOD 1: Using Brute Force

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int result = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += arr[j];
                if(sum == 0){
                    result = max(result, j - i + 1);
                }
            }
        }
        
        return result;
    }
};


// METHOD 2: Using HashMap Logic
// if you are getting a sum which you have seen before than it means from that index till current index your sum is zero, just calculate the length of the subarry

class Solution {
  public:
    int n;
    int maxLength(vector<int>& arr) {
        // code here
        n = arr.size();
        
        unordered_map<int, int> mp;
        
        int sum = 0;
        int result = 0;
        
        for(int i = 0; i < n; i++){
            sum = sum + arr[i];
            if(sum == 0){
                result = i+1;
            }
            else{
                if(mp.find(sum) != mp.end()){
                    int preIdx = mp[sum];
                    result = max(result, i - preIdx);
                }
                else{
                    mp[sum] = i;
                }
            }
        }
        
        return result;
        
    }
};
