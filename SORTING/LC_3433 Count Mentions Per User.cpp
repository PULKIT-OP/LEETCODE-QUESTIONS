// Question Link: https://leetcode.com/problems/count-mentions-per-user/description/

// Here first we sort the events string based on the timestamp they were sent. if the timestamp is same then we give priority to the event which was given to offline user in simeple words we have to give priority to the user who is online and to make him online if he is offline to count his mention
// so for that purpose we use lambda function to sort according to our need mention above
// we make to vectors to store mentionCount to store no. of mentions per user nd offlineTime to store the time when a user got offline.
// after all this we run a for loop on events, if we find "MESSAGE" then we call applyMessageEvent function which tackles the message event.
      // in this fucntion we pass that particular event string, mentionCount array, and offlineTime array.
      // then we store the timestamp of that event
      // then we make ids array to store all the ids which are mention in that event string using stringstream.
      // then we run a for loop on all the mention ids on id array.
      // if the id says "ALL" then increase the mentionCount of all the ids.
      // else if the id says "HERE" then check if the offlineTime is zero or offlineTime + 60 is less than the timestamp of this event for all the ids. if yes then increase the mention of the ids.
      // else means that particular ids are mention in that event so, we extract the id no form that string then increase the mention of that id in mentionCount. and all set we completed the applyMessageEvent function then will be called if any event says "MESSAGE" 
// else if the event says "OFFLINE" menas a user got offline then we store its timeStamp, its id and we update the offline time of this user in offlineTime array.
// then at last we return the mentionCount array


class Solution {
public:

    void applyMessageEvent(vector<string> event, vector<int> &mentionCount, vector<int> offlineTime){
        int timeStamp = stoi(event[1]);

        vector<string> ids;

        stringstream ss(event[2]);

        string token;

        while(ss >> token){     // default me whitespaces ke basis pr token ko break kr deta hai
            ids.push_back(token);
        }

        for(string id : ids){
            if(id == "ALL"){
                for(int i = 0; i < mentionCount.size(); i++){
                    mentionCount[i]++;
                }
            }
            else if(id == "HERE"){
                for(int i = 0; i < mentionCount.size(); i++){
                    if(offlineTime[i] == 0 || offlineTime[i]+60 <= timeStamp){
                        mentionCount[i]++;
                    }
                }
            }
            else{
                mentionCount[stoi(id.substr(2))]++;     // fetching id value i.e: x form idx
            }
        }
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentionCount(numberOfUsers);
        vector<int> offlineTime(numberOfUsers);

        // writing lambda function for our sorting
        auto lambda = [](vector<string> &vec1, vector<string> &vec2){
            int t1 = stoi(vec1[1]);
            int t2 = stoi(vec2[1]);
            if(vec1[1] == vec2[1]){
                return vec1[0][1] > vec2[0][1];     //comparing first letter of "MESSAGE" and "OFFLINE"
            }
            return t1 < t2;
        };

        sort(events.begin(), events.end(), lambda);

        for(vector<string> event : events){
            if(event[0] == "MESSAGE"){
                applyMessageEvent(event, mentionCount, offlineTime);
            }
            else if(event[0] == "OFFLINE"){
                int timeStamp = stoi(event[1]);
                int id = stoi(event[2]);
                offlineTime[id] = timeStamp;
            }
        }

        return mentionCount;

    }
};
