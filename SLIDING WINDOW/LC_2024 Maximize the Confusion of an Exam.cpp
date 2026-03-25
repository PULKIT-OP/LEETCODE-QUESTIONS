// Question Link: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/


// METHOD 1: SLIDING WINDOW  ---> used two functions for true count and for false count

class Solution {
public:
    int n;
    int solve_true(string answerKey, int k){
        int i = 0;
        int j = 0;

        int count = 0;
        int maxi = INT_MIN;

        while(j < n){
            if(answerKey[j] != 'T'){
                count++;
            }
            while(i <= j && count > k){
                if(answerKey[i] == 'F'){
                    count--;
                }
                i++;
            }
            maxi = max(maxi, j - i + 1);

            j++;
        }

        return maxi;
    }
    int solve_false(string answerKey, int k){
        int i = 0;
        int j = 0;

        int count = 0;
        int maxi = INT_MIN;

        while(j < n){
            if(answerKey[j] != 'F'){
                count++;
            }
            while(i <= j && count > k){
                if(answerKey[i] == 'T'){
                    count--;
                }
                i++;
            }

            maxi = max(maxi, j - i + 1);

            j++;
        }

        return maxi;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        n = answerKey.length();

        int true_count = solve_true(answerKey, k);
        int false_count = solve_false(answerKey, k);

        return max(true_count, false_count);
    }
};
