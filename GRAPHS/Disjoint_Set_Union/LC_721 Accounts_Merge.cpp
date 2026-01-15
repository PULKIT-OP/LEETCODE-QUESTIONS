// Question Link: https://leetcode.com/problems/accounts-merge/

// METHOD 1: DSU ---> UNION FIND

// First, map all the mails to its index, if you find any mail which is already present in map then take union of that index and current index.
// Otherwise continue mapping
// After mapping done, You start making vector mails at its index
// then start storing it in final answer

class Solution {
public:
    int find(int x, vector<int> &parent){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x], parent);
    }
    void Union(int x, int y, vector<int> &parent, vector<int> &rank){
        int par_x = find(x, parent);
        int par_y = find(y, parent);

        if(par_x == par_y){
            return;
        }

        if(rank[par_x] > rank[par_y]){
            parent[par_y] = par_x;
        }
        else if(rank[par_y] > rank[par_x]){
            parent[par_x] = par_y;
        }
        else{
            parent[par_x] = par_y;
            rank[par_y]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        unordered_map<string, int> mp;

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        vector<int> rank(n, 0);

      // Mapping emails to its index
        for(int j = 0; j < n; j++){
            int size = accounts[j].size();
            for(int i = 1; i < size; i++){
                string st = accounts[j][i];
                if(mp.find(st) == mp.end()){
                    mp[st] = j;
                }
                  // if I find already mapped email then take Union of already mapped index and current index
                else{
                    Union(mp[st], j, parent, rank);
                }
            }
        }

      // Now fill up emails in their index absolute index(parent)
        vector<vector<string>> mails(n);
        for(auto &e : mp){
            string gmail = e.first;
            int node = find(e.second, parent);
            mails[node].push_back(gmail);
        }

      // Vector to store final answer
        vector<vector<string>> result;

        for(int i = 0; i < n; i++){
          // if index is empty continue
            if(mails[i].size() == 0){
                continue;
            }
          // before storing it to answer sort it 
            sort(mails[i].begin(), mails[i].end());
          // make a temporaty array to store sorted mails
            vector<string> temp;
          // firstly push Name
            temp.push_back(accounts[i][0]);
          // then push all the mails which we sorted earlier
            for(auto &it: mails[i]){
                temp.push_back(it);
            }
          // then push temp array in final reuslt
            result.push_back(temp);
        }
      // then return result
        return result;
    }
};
