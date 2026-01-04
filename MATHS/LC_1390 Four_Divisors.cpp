// Question Link: 

// METHOD 1: BRUTE FORCE METHOD ----> NOT RECOMMENDED ---> TLE milega LAADLE

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for(auto &e : nums){
            if(mp.count(e)){
                continue;
            }
            for(int i = 1; i <= e; i++){
                if(e%i == 0){
                    mp[e].push_back(i);
                }
            }
        }

        int ans = 0;

        for(auto &e : nums){
            if(mp[e].size() == 4){
                for(int i = 0; i < 4; i++){
                    ans += mp[e][i];
                }
            }
        }
        return ans;
    }
};


// METHOD 2: Maths MAGIC APPROACH
// In this method we will be using some properites of numbers and divisor
// Property 1: all divisors you find will be in pairs. For ex: if divisor of 21 is 3 then 21/3 will also be a divisior, so we get two divisors from one divisor --> {3, 21/3}
// Property 2: You just have to check till square root of num to get all the divisor. ----> for each divisor you willl get two divisor
// Property 3: Be cautious on this corner case ----> if you get a number which is perfect square like 36 then its sqrt(36) --> 6 so you wiill get a pair of divisor {6, 6} so keep in mind in this case you are just getting oen divisor not two divisor 

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
      // to store final sum 
        int result = 0;

      // iterating over nums
        for(auto &e : nums){
          // to store count of divisors and total sum of divisors for each number
            int count = 0;
            int sum = 0;
          // to storing if we get any number which has divisor count greater than 4
            bool greater = false;

          // iterating over each number till its square root
            for(int i = 1; i <= sqrt(e); i++){
              // if you get any divisor then check if it has pair of same divisor if yes then count it once if not then count 2 divisor
                if(e%i == 0){
                    if(i == e/i){
                        count++;
                        sum += i;
                    }
                    else{
                        count += 2;
                        sum += (i + e/i);
                    }
                }

              // now after each iteration on number check if it has crossed divisor count > 4, if yes then mark greater = true;
                if(count > 4){
                    greater = true;
                    break;
                }
            }
          // after for loop ends check if you have count greater than 4 then continue
            if(greater == true){
                continue;
            }
          // if not then add then divisor sum in your final result
            if(count == 4){
                result += sum;
            }
        }

      // at last return your final result
        return result;
    }
};
