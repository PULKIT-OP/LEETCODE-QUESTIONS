// Question Link: https://www.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1

// In this algorithm you just have to return all the prime numbers bw 1 to n.
// To get that you just need to mark all the multiples of prime numbers false till n
// Then remaining numbers which are marked true will be your prime numbers

class Solution {
  public:
    vector<int> sieve(int n) {
        // make isPrime array and mark all the numbers as prime
      // but we know 0 and 1 are not prime so mark that as well
        vector<bool> isPrime(n+1, true);
        isPrime[0] = false;
        isPrime[1] = false;

      // Now you just need to check from 2 to root(n) because ---> you will get all the factors of n till root(n).
        for(int i = 2; i*i <= n; i++){
          // Now check each factor if it is prime ---> if yes then mark all its multiples as false
            if(isPrime[i] == true){
              // its multiple will be till n so you just need to run your loop till its not equals to n and mark all the multiples as false
                for(int j = 2; i*j <= n; j++){
                    isPrime[i*j] = false;
                }
            }
        }

      // then make a result array and push all the numbers marked as true ---> these numbers are prime numbers and return this array
        vector<int> result;
        for(int i = 0; i <= n; i++){
            if(isPrime[i] == true){
                result.push_back(i);
            }
        }
        
        return result;
    }
};
