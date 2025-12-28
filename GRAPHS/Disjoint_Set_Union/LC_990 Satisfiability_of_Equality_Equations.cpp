// Question Link: https://leetcode.com/problems/satisfiability-of-equality-equations/

// METHOD 1: USING DSU  ---> FIND and UNION method

// Here logic is simple, we are just making tree with the given equations at any point if we find contradiction we return false

class Solution {
public:

    int find(int x, vector<int> &parent){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x], parent);
    }

    void Union(int x, int y, vector<int> &parent, vector<int> &rank){
        int x_par = find(x, parent);
        int y_par = find(y, parent);

        if(x_par == y_par){
            return;
        }
        if(x_par > y_par){
            parent[y_par] = x_par;
        }
        else if(y_par > x_par){
            parent[x_par] = y_par;
        }
        else{
            parent[y_par] = x_par;
            rank[x_par]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<int> rank(26, 0);

        for(int i = 0; i < 26; i++){
            parent[i] = i;
        }
        for(auto &v : equations){
            int x = v[0] - 'a';
            int y = v[3] - 'a';
            int sign = v[1];

          // Here we are checking if the equation says '==', then union both the variable means join them
            if(sign == '='){
                Union(x, y, parent, rank);
            }
        }
        for(auto &v : equations){
            int x = v[0] - 'a';
            int y = v[3] - 'a';
            int sign = v[1];

          // Here we are cheking if the equation says '!=', then check if their parents are equal, if yes then it is contradicting its previous statements ---> return false
            if(sign == '!'){
                int x_par = find(x, parent);
                int y_par = find(y, parent);

                if(x_par == y_par){
                    return false;
                }
            }
        }
      // If never contradicts and loop ends means all statements are true so return true
        return true;
    }
};
