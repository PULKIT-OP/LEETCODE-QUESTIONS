// Question Link: https://leetcode.com/problems/count-days-spent-together/description


// METHOD 1: Most optimal method 
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        string start = max(arriveAlice, arriveBob);
        string end = min(leaveAlice, leaveBob);

        if(start > end) return 0;

        int startMonth = stoi(start.substr(0, 2));
        int startDay = stoi(start.substr(3, 2));
        int endMonth = stoi(end.substr(0, 2));
        int endDay = stoi(end.substr(3, 2));

        int incomingDay = floor(275*startMonth/9) - 2*(floor((startMonth + 9)/12)) + startDay - 30;
        int outGoingDay = floor(275*endMonth/9) - 2*(floor((endMonth + 9)/12)) + endDay - 30;

        int overLappingDays = outGoingDay - incomingDay + 1;
        return overLappingDays < 0 ? 0 : overLappingDays;
    }
};
