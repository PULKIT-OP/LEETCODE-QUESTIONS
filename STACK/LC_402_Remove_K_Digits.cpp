// Question Link: https://leetcode.com/problems/remove-k-digits/description/


// METHOD 1: Using Stack

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
      // if k is n then remove all elements so return 0
        if(k == n){
            return "0";
        }
        stack<char> st;
        for(int i = 0; i < n; i++){
          // if top of stack is greater than nums[i] --> remove it and count it as deleteed
          // we deleting it greater elements bcoz we need smaller digits in starting ----> to make overall number as smaller as possible
            while(!st.empty() && k > 0 && st.top() - '0' > num[i] - '0'){
                st.pop();
                k = k-1;
            }
          // after removing greater elements push current element
            st.push(num[i]);
        }

      // Now check if still deletes remaining then delete top elements from stack 
        while(k > 0){
            st.pop();
            k--;
        }
      // if your stack is empty --> means no element reaming to return so return "0"
        if(st.empty()){
            return "0";
        }

      // Now returning result
        string result = "";
      // store stack elements in result
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
      // removing leading zeroes
        while(result.length() != 0 && result.back() == '0'){
            result.pop_back();
        }
        // reversing it 
        reverse(result.begin(), result.end());

      // return it carefully
        if(result.length() == 0){
            return "0";
        }

        return result;
    }
};
