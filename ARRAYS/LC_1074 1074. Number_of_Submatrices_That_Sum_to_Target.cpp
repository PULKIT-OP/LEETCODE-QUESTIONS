// Question Link: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/

// METHOD 1: 

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        // row wise cumulative sum
        for(int i = 0; i < m; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                sum += matrix[i][j];
                matrix[i][j] = sum;
            }
        }

        // submatrix sum just like problem LC_560 but in downwards direction 
        int result = 0;
        for(int st_col = 0; st_col < n; st_col++){
            for(int col = st_col; col < n; col++){
                unordered_map<int, int> mp;
                mp[0]++;
                int sum = 0;
                for(int row = 0; row < m; row++){
                    sum += matrix[row][col] - (st_col > 0 ? matrix[row][st_col-1] : 0);
                    if(mp.find(sum - target) != mp.end()){
                        result += mp[sum - target];
                    }
                    mp[sum]++;
                }
            }
        }
      
        return result;
    }
};
