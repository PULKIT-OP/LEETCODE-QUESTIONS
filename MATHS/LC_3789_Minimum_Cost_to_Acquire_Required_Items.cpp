// Question Link: https://leetcode.com/problems/minimum-cost-to-acquire-required-items/description



// METHOD 1: Using MATHS or you can say normal conditions to fulfill the requirement

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long one, two, three;
        
        one = 1LL * max(need1, need2) * costBoth;

        if(need1 < need2){
            two = 1LL * costBoth * need1;
            int rem = need2 - need1;
            two += (1LL * rem * cost2);
        }
        else if(need2 <= need1){
            two = 1LL * costBoth * need2;
            int rem = need1 - need2;
            two += (1LL * rem * cost1);
        }

        three = (1LL * cost1 * need1) + (1LL * cost2 * need2);

        return min({one, two, three});
    }
};
