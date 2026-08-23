// Question Link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1


// METHOD 1: BruteForce method ---> O(n^2) time and space -> O(n)

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        vector<int> pplKnow(n, 1);  // How many people know ith person
        vector<int> knowPPl(n, 1);  // how many people does ith person recognize
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && mat[i][j] == 1){
                    pplKnow[j]++;
                    if(mat[j][i] == 1){
                        knowPPl[i]++;
                    }
                }
            }
        }
        
        int ans = -1;
        for(int i = 0; i < n; i++){
            if(pplKnow[i] == n && knowPPl[i] == 1){
                ans = i;
            }
        }
        
        return ans;
    }
};

// METHOD 2: Using Two Poiters --> O(n)

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        int a = 0;
        int b = n-1;
        
        while(a < b){
            if(a != b && mat[a][b] == 1){
                // a knows b ---> a cannot be celebrity
                a++;
            }
            else{
                // a doesnot know b ---> b cannot be celebrity
                b--;
            }
        }
        
        int ans = a;
        for(int i = 0; i < n; i++){
            if(i == ans){
                continue;
            }
            
            if(mat[i][ans] == 0 || mat[ans][i] == 1){
                return -1;
            }
        }
        
        return ans;
    }
};
