// Question Link: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/


// METHOD 1: Using DSU Logic

class Solution {
public:
    int find(int x, vector<int> &parent){
        if(x == parent[x]){
            return x;
        }

        return parent[x] = find(parent[x], parent);
    }
    void Union(int x, int y, vector<int> &rank, vector<int> &parent){
        if(rank[x] > rank[y]){
            parent[y] = x;
        }
        else if(rank[y] > rank[x]){
            parent[x] = y;
        }
        else{
            parent[y] = x;
            rank[x]++;
        }
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        vector<int> parentAlice(n+1);
        vector<int> parentBob(n+1);
        vector<int> rankAlice(n+1, 1);
        vector<int> rankBob(n+1, 1);

        for(int i = 0; i <= n; i++){
            parentAlice[i] = i;
            parentBob[i] = i;
        }

        // for type 3
        int count = 0;
        for(auto &e : edges){
            int type = e[0];
            int u = e[1];
            int v = e[2];

            if(type == 3){
                int upa = find(u, parentAlice);
                int vpa = find(v, parentAlice);
                int upb = find(u, parentBob);
                int vpb = find(v, parentBob);
                if(upa == vpa && upb == vpb){
                    count++;
                }
                else{
                    Union(upa, vpa, rankAlice, parentAlice);
                    Union(upb, vpb, rankBob, parentBob);
                }
            }
        }

        for(auto &e : edges){
            int type = e[0];
            int u = e[1];
            int v = e[2];

            if(type == 1){
                int up = find(u, parentAlice);
                int vp = find(v, parentAlice);
                if(up == vp){
                    count++;
                }
                else{
                    Union(up, vp, rankAlice, parentAlice);
                }
            }
            else if(type == 2){
                int up = find(u, parentBob);
                int vp = find(v, parentBob);
                if(up == vp){
                    count++;
                }
                else{
                    Union(up, vp, rankBob, parentBob);
                }
            }
        }

      // Checking if anyone left that cant be traversed, if found return -1
        int aliceComponents = 0;
        int bobComponents = 0;
        for(int i = 1; i <= n; i++){
            if(parentAlice[i] == i){
                aliceComponents++;
            }
            if(parentBob[i] == i){
                bobComponents++;
            }
        }

        if(aliceComponents != 1 || bobComponents != 1){
            return -1;
        }

        return count;

    }
};
