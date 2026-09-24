// Question Link: https://leetcode.com/problems/keys-and-rooms/description/


// METHOD 1: Using DFS, Its a simple and direct DFS application nothing to think twice

class Solution {
public:
    int n;
    void DFS(vector<vector<int>>& rooms, int room, vector<bool> &visited){
        for(auto e : rooms[room]){
            if(!visited[e]){
                visited[e] = true;
                DFS(rooms, e, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();

        vector<bool> visited(n, false);
        visited[0] = true;
        DFS(rooms, 0, visited);

        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                return false;
            }
        }

        return true;
    }
};


// METHOD 2: Using BFS

class Solution {
public:
    int n;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();

        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int key = q.front();
            q.pop();

            for(auto e : rooms[key]){
                if(!visited[e]){
                    visited[e] = true;
                    q.push({e});
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                return false;
            }
        }

        return true;
    }
};
