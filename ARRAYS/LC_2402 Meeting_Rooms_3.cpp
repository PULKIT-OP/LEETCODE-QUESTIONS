// Question Link: https://leetcode.com/problems/meeting-rooms-iii/description/

// METHOD 1: BRUTE FORCE    --->  Might get TLE    T.C --> O(n*m)
// 1. Sort the meetings based on start time
// 2. Find the first room that can be used for current meeting ----> you might end up getting empty rooms or you will find no rooms empty.
// if you get no room empty then look for the room which gets empty first like the end time for that room. if 2 rooms are having same end time then go for the room with lowest room number

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(meetings.begin(), meetings.end());     // sorting based on start time

        vector<long long> finishTime(n, 0);
        vector<int> count(n, 0);
        for(int i = 0; i < m; i++){
            bool found = false;
            int start = meetings[i][0];
            int end = meetings[i][1];
            long long Total_time = end - start;
            long long smallTime = LLONG_MAX;
            int smallRoom = INT_MAX;
            for(int room = 0; room < n; room++){
                if(finishTime[room] <= start){
                    finishTime[room] = end;
                    count[room]++;
                    found = true;
                    break;
                }
                if(finishTime[room] < smallTime){
                    smallTime = finishTime[room];
                    smallRoom = room;
                }
            }

            if(found == false){
                finishTime[smallRoom] += Total_time;
                count[smallRoom]++;
            }
        }

        int room = 0;
        int meet_count = INT_MIN;
        for(int i = 0; i < n; i++){
            if(count[i] > meet_count){
                meet_count = count[i];
                room = i;
            }
        }
        return room;
    }
};


// METHOD 2:


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(meetings.begin(), meetings.end());     // sorting based on start time

        vector<int> count(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> usedRoom;

        priority_queue<int, vector<int>, greater<int>> availableRooms;

        for(int room = 0; room < n; room++){
            availableRooms.push(room);
        }

        for(vector<int> meet : meetings){
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;

            while(!usedRoom.empty() && usedRoom.top().first <= start){
                int room = usedRoom.top().second;
                usedRoom.pop();
                availableRooms.push(room);
            }

            if(!availableRooms.empty()){
                int room = availableRooms.top();
                availableRooms.pop();
                usedRoom.push({end, room});
                count[room]++;
            }
            else{
                int room = usedRoom.top().second;
                long long endTime = usedRoom.top().first;

                usedRoom.pop();

                usedRoom.push({endTime + duration, room});
                count[room]++;
            }
        }

        int room = -1;
        int maxCount = INT_MIN;
        for(int i = 0; i < n; i++){
            if(count[i] > maxCount){
                maxCount = count[i];
                room = i;
            }
        }

        return room;
    }
};
