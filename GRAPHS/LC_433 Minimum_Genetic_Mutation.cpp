// Question Link: https://leetcode.com/problems/minimum-genetic-mutation/


// METHOD 1: Using BFS

class Solution {
public:
    unordered_map<string, bool> visited;
    queue<string> que;
    vector<char> gene = {'A', 'C', 'G', 'T'};
    set<string> bank_st;

    bool exist(string test){
        if(bank_st.find(test) != bank_st.end()){
            return true;
        }
        return false;
    }

    int BFS(string startGene, string endGene){
        int count = 0;

        while(!que.empty()){
            int size = que.size();

            for(int s = 0; s < size; s++){
                string u = que.front();
                que.pop();

                for(int m = 0; m < u.length(); m++){
                    for(int i = 0; i < 4; i++){
                        string test = u;
                        test[m] = gene[i];
                        if(visited[test]){
                            continue;
                        }
                        else{
                            if(exist(test)){
                                if(test == endGene){
                                    return count+1;
                                }
                                visited[test] = true;
                                que.push(test);
                            }
                        }
                    }
                }
            }

            count++;
        }

        return -1;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        for(int i = 0; i < bank.size(); i++){
            bank_st.insert(bank[i]);
        }

        if(bank_st.find(endGene) == bank_st.end()){
            return -1;
        }
        
        que.push(startGene);
        
        return BFS(startGene, endGene);
    }
};
