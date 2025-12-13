// Question Link: 

// Method 1: simple not optimized method brute force method  main concept used is sorting using lambda function

class Solution {
public:
    // here checking is the coupon code is correct or not
    bool correctCode(string code){
        int n = code.length();
        if(code.empty()){
            return false;
        }
        for(char c : code){
            if(!isalnum(c) && c != '_'){
                return false;
            }
        }
        return true;
    }

    // here checking if the businessLine mention is correct or not.
    bool correctBusiness(string business){
        if((business) == "electronics" || (business) == "grocery" || (business) == "pharmacy" || (business) == "restaurant"){
            return true;
        }
        return false;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string, string>> ans;    // to store business and code as a pair of valid coupons.

        for(int i = 0; i < n; i++){
            if(isActive[i] == true){
                if(correctCode(code[i]) == true){
                    if(correctBusiness(businessLine[i]) == true){
                        pair<string, string> p = {businessLine[i], code[i]};
                        ans.push_back(p);
                    }
                }
            }
        }

      // lambda function for sorting based on business order and then code lexo order
        auto lambda = [](pair<string, string> p1, pair<string, string> p2){
            string business_1 = p1.first;
            string code_1 = p1.second;
            string business_2 = p2.first;
            string code_2 = p2.second;

          // here comparing the first letter of the businesses 
            if(business_1[0] == business_2[0]){ 
              // lexo order checking
                return p1.second < p2.second;
            }
            return business_1[0] < business_2[0];
        };

      // sorting
        sort(ans.begin(), ans.end(), lambda);

        vector<string>finalAns;
      // now pushing the sorted codes in the finalAns array
        for(auto &v : ans){
            finalAns.push_back(v.second);
        }
        return finalAns;
    }
};
