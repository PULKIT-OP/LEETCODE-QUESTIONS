// Question Link: https://leetcode.com/problems/open-the-lock/


// METHOD 1: Kinda brute Force method, here we are checking each possibility using bfs

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

      // storing deadends in set for better iteration over it
        unordered_set<string> visited;
        for(auto &e : deadends){
            visited.insert(e);
        }

      // if strating is in deadends then we cant proceed so return -1
        if(visited.find("0000") != visited.end()){
            return -1;
        }

        queue<string> q;
        q.push("0000");
        visited.insert("0000");

        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string code = q.front();
                q.pop();
              // if found target then return steps
                if(code == target){
                    return steps;
                }
                for(int i = 0; i < 4; i++){
                    char ch = code[i]; // storing current character in code
                  // increment by one then check if its deadend and then store it
                    char inc = (ch == '9') ? '0' : ch + 1;
                    code[i] = inc;
                    if(visited.find(code) == visited.end()){
                        q.push(code);
                        visited.insert(code);
                    }
                  // decrement by one then check if its deadend and then store it
                    char dec = (ch == '0') ? '9' : ch - 1;
                    code[i] = dec;
                    if(visited.find(code) == visited.end()){
                        q.push(code);
                        visited.insert(code);
                    }
                  // now redo the changes in code and move forward
                    code[i] = ch;
                }
            }
            steps++; // increment steps after each iteration
        }

        return -1;   // return -1 if cant find any route to target
    }
};
