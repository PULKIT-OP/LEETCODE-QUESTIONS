// Question Link: https://leetcode.com/problems/word-ladder/

// METHOD 1: USING BFS --> THE SAME LOGIC USED IN MININUM GENETIC MUTATION(LC_433)

class Solution {
public:
    set<string> visited;
    queue<string> que;
    set<string> bank_st;

    bool exist(string test){
        if(bank_st.find(test) != bank_st.end()){
            return true;
        }
        return false;
    }

    int BFS(string beginWord, string endWord){
        int count = 0;

        while(!que.empty()){
            int size = que.size();

            for(int s = 0; s < size; s++){
                string u = que.front();
                que.pop();

                for(int m = 0; m < u.length(); m++){
                    for(char i = 'a'; i <= 'z'; i++){
                        string test = u;
                        test[m] = i;
                    if(visited.find(test) != visited.end()){
                            continue;
                        }
                        else{
                            if(exist(test)){
                                if(test == endWord){
                                    return count+1;
                                }
                                visited.insert(test);
                                que.push(test);
                            }
                        }
                    }
                }
            }

            count++;
        }

        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(int i = 0; i < wordList.size(); i++){
            bank_st.insert(wordList[i]);
        }

        if(bank_st.find(endWord) == bank_st.end()){
            return 0;
        }
        
        que.push(beginWord);

        int ans = BFS(beginWord, endWord);
        return (ans == 0 ? 0 : ans + 1);
    }
};


// after first optimization

class Solution {
public:
    set<string> visited;
    queue<string> que;
    set<string> bank_st;

    bool exist(string test){
        if(bank_st.find(test) != bank_st.end()){
            return true;
        }
        return false;
    }

    int BFS(string beginWord, string endWord){
        int count = 0;

        while(!que.empty()){
            int size = que.size();

            for(int s = 0; s < size; s++){
                string u = que.front();
                que.pop();

                for(int m = 0; m < u.length(); m++){
                    for(char i = 'a'; i <= 'z'; i++){
                        string test = u;
                        test[m] = i;
                    if(visited.find(test) != visited.end()){
                            continue;
                        }
                        else{
                            if(exist(test)){
                                if(test == endWord){
                                    return count+1;
                                }
                                visited.insert(test);
                                que.push(test);
                            }
                        }
                    }
                }
            }

            count++;
        }

        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(int i = 0; i < wordList.size(); i++){
            bank_st.insert(wordList[i]);
        }

        if(bank_st.find(endWord) == bank_st.end()){
            return 0;
        }
        
        que.push(beginWord);

        int ans = BFS(beginWord, endWord);
        
        return (ans == 0 ? 0 : ans + 1);
    }
};

// after second optimization ---> instead of storing visited words in that set i removed the word form the bank so that i never visit that again.

class Solution {
public:
    queue<string> que;
    set<string> bank_st;

    bool exist(string test) {
        if (bank_st.find(test) != bank_st.end()) {
            return true;
        }
        return false;
    }

    int BFS(string beginWord, string endWord) {
        int count = 0;

        while (!que.empty()) {
            int size = que.size();

            for (int s = 0; s < size; s++) {
                string u = que.front();
                que.pop();

                for (int m = 0; m < u.length(); m++) {
                    for (char i = 'a'; i <= 'z'; i++) {
                        string test = u;
                        test[m] = i;

                        if (exist(test)) {
                            if (test == endWord) {
                                return count + 1;
                            }
                            bank_st.erase(test);
                            que.push(test);
                        }
                    }
                }
            }

            count++;
        }

        return 0;
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        for (int i = 0; i < wordList.size(); i++) {
            bank_st.insert(wordList[i]);
        }

        if (bank_st.find(endWord) == bank_st.end()) {
            return 0;
        }

        que.push(beginWord);

        int ans = BFS(beginWord, endWord);

        return (ans == 0 ? 0 : ans + 1);
    }
};


// after 3rd optimization ---> i checked the letter, if that is same than just continue no need to check for that

class Solution {
public:
    queue<string> que;
    set<string> bank_st;

    bool exist(string test) {
        if (bank_st.find(test) != bank_st.end()) {
            return true;
        }
        return false;
    }

    int BFS(string beginWord, string endWord) {
        int count = 0;

        while (!que.empty()) {
            int size = que.size();

            for (int s = 0; s < size; s++) {
                string u = que.front();
                que.pop();

                for (int m = 0; m < u.length(); m++) {
                    for (char i = 'a'; i <= 'z'; i++) {
                        string test = u;
                        if(test[m] == i) continue;  // ---> this one
                        test[m] = i;

                        if (exist(test)) {
                            if (test == endWord) {
                                return count + 1;
                            }
                            bank_st.erase(test);
                            que.push(test);
                        }
                    }
                }
            }

            count++;
        }

        return 0;
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        for (int i = 0; i < wordList.size(); i++) {
            bank_st.insert(wordList[i]);
        }

        if (bank_st.find(endWord) == bank_st.end()) {
            return 0;
        }

        que.push(beginWord);

        int ans = BFS(beginWord, endWord);

        return (ans == 0 ? 0 : ans + 1);
    }
};
