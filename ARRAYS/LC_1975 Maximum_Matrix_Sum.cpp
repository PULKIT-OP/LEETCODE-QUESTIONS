// Question Link: 

// METHOD 1: OBSERVATION ----> Just observe the exmaples try dry run and you will get it
// Here you just need to find out the maximum possible sum you can get by multiplying adjacent two cells by 1
// If you observe ---> If total negative numbers in matrix are even then we can convert all of them into positive but but but if there are odd number of negative number after multiplying adjacent by 1 you will left with single negative number in matrix 
// And this thing is the catch of this problem ---> you just hve to find out total negative numbers in matrix if that is even then just return the total sum of the matirx 
// And if that is odd then you just have to return then total absolute sum of matrix - 2*minimum element of matirx

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int neg = 0;
        int min = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0){
                    neg++;
                }
                if(abs(matrix[i][j]) < min){
                    min = abs(matrix[i][j]);
                }
            }
        }

        if(neg%2 == 0){
            return sum;
        }

        return sum - min - min;
    }
};
