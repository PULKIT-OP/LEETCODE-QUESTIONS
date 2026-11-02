// Question Link: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/


// METHOD 1: Smallest + Largest Combining, after sorting the array

class Solution {
public:
    int n;
    long long dividePlayers(vector<int>& skill) {
        n = skill.size();
        sort(skill.begin(), skill.end());

        long long count = (skill[0] * skill[n-1]);
        int total_skill = skill[0] + skill[n-1];
        for(int i = 1; i < n/2; i++){
            if(skill[i] + skill[n-i-1] != total_skill){
                return -1;
            }
            count += (skill[i] * skill[n-i-1]);
        }

        return count;
    }
};
