// Question Link: https://leetcode.com/problems/word-ladder-ii/description/


// METHOD 1: WILL GIVE MLE or TLE ON LEETCODE
// But its a goood Solution for interviews and for solutions may be on different platforms other than LEETCODE

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;  // To store the wordList 
        vector<vector<string>> result;  // to store the final answer
        bool found = false;
      // filling up the set and checking if endWord exist in wordList or not if not return empty list right there
        for(int i = 0; i < wordList.size(); i++){
            st.insert(wordList[i]);
            if(wordList[i] == endWord){
                found = true;
            }
        }
        if(found == false){
            return result;
        }
        queue<vector<string>> q;  // que of vector of string
        q.push({beginWord});  // pushing list with beginWord
        vector<string> usedOnLevel;  // to store the words which are being used in current level (its like marking them visited in this level)
        usedOnLevel.push_back(beginWord); // in starting beginword will be there 
        int level = 0;  // we havnt started yet so we are in level 0

      // BFS Traversal
        while(!q.empty()){
            vector<string> vec = q.front();  // getting the vector from the que
            q.pop();

          // if size of vector is greater than level means we have entered in next level
            if(vec.size() > level){
                level++;  // so just increment the level
                // and erase all the elements which are of previous level from the set because we are not gonna use them in this level as they are used
                for(auto &it : usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear(); // As the elements of this level are being removed so we should empty previous level elements as well which are being marked visited
            }

          // take out last element of vector 
            string word = vec.back();
          // if this word is equals to endword ---> we got one sequence
            if(word == endWord){
                // so check if we have any other sequence in the result 
                if(result.size() == 0){
                  // if not then just push in result
                    result.push_back(vec);
                }
                  // otherwise only push the sequence which are of same size if its bigger then its rejected
                else if(result[0].size() == vec.size()){
                    result.push_back(vec);
                }
            }

          // if the word was not equals to endword then just do same thing iterat over each character and try to find the exact match
            for(int i = 0; i < word.length(); i++){
                char original = word[i];  // store original character at ith index
                for(char ch = 'a'; ch <= 'z'; ch++){
                  // if both character are same then just continue because nothing gonna change in the word
                    if(ch == original){
                        continue;
                    }
                    word[i] = ch; // otherwise update the word

                  // Now check if it exist in our wordList 
                    if(st.find(word) != st.end()){
                      // if yes then push in the vector 
                        vec.push_back(word);
                      // then push in queue --> as we got a new sequence
                        q.push(vec);
                        // mark as visited on this level -> because we got a new word in this level 
                        usedOnLevel.push_back(word);
                      // then pop from the vector as we need to check for other character and words as well in this same sequence
                      // for example : vec = hot, pot --> last element = pot --> we iterate over each character and we found 'pet' exist in wordList
                      // so we push 'pet' in vec it becomes --> hot, pot, pet now push this in queue
                      // then remove pet from the vector so it becomes hot, pot again and iteration over pot remains and if we find any other word like 'pit' we gonna push in vec then push in que and so on
                        vec.pop_back();
                    }
                }
              // at last restore the original word
                word[i] = original;
            }
        }

        return result; // then return result

    }
};


// METHOD 2: One of the hardest code
// Main logic of this code is simple : Earlier we used to start from begin word and tried to find all possible paths to reach endWord and uncessarily storing words
// but here we are tracking from back and reaching to beginWord
// before doiing the backtracking we first store all the words in map with its distance or levels then based on that we find our answer later in step 2

// TRY 2 - 3 DRY RUNS TO UNDERSTAND IT BETTER

class Solution {
public:
    unordered_map<string, int> mp;  // to store distance (level)
    vector<vector<string>> result;
    string b;
    // Now DFS
    void DFS(string &word, vector<string> &seq){
      // if the word is beginWord it means we got a sequence
        if(word == b){
          // so reverse the sequence and push in result and then again reveerse it for further computation and return
            reverse(seq.begin(), seq.end());
            result.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
      // if word is not begin word then
        int steps = mp[word];  // take out steps from map
        int sz = word.size();  // size of the word
      // Now same character iteration and checking
        for(int i = 0; i < sz; i++){
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
              // if you find the word which is in map AND AND AND if its level is equals to steps then push it in sequence and then call DFS for this word and then pop_back from sequence
                if(mp.find(word) != mp.end() && mp[word] + 1 == steps){
                    seq.push_back(word);
                    DFS(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;  // restoring original word
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());  // storing all the words from wordlist
        b = beginWord;  // storing beginwrod for later usecase
        queue<string> q;  
        q.push({beginWord});
        st.erase(beginWord);  // after pushing beginword we erase it from wordlist so that code doesnt halucinate(revisit same word)
        mp[beginWord] = 1; // storing beignword in map and marking its level as 1 
        int sz = beginWord.size();  

      // Now BFS
        while(!q.empty()){
            string word = q.front();  // get the word from queue
            q.pop();
            int steps = mp[word];  // get its steps from map

            if(word == endWord){  // if we reached to last word then just break it because now we need to backtrack otherwise continue until you reaach lastword
                break;
            }

          // same as before try to iterate over each letter of each word and find out word froom wordlist(st set)
            for(int i = 0; i < sz; i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){  // if found a word that matches 
                        q.push(word);  // push in que
                        st.erase(word);  // then erase it from set so no revisit
                        mp[word] = steps + 1; // then store its step in map 
                    }

                }
                word[i] = original;  // restore original word
            }
        }

      // Now check if you found endword if yes then this will continue otherwise return empty result
        if(mp.find(endWord) != mp.end()){
            vector<string> seq;  // to store the sequence if we get any
            seq.push_back(endWord);  // initially store endword in it (because we are backtracking to endword is in starting but dont worry before pushing it in final result we gonna reverse it)
            DFS(endWord, seq);  // Now call DFS --> this will find out the paths from end word to beginWord if it exist and store it in sequence
        }

        return result;
    }
};
