// Question Link: https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1

// METHOD 1: Normal method with O(n) complexity

int find(int par[], int x) {
    if(par[x] == x){
        return x;
    }
    
    return find(par, par[x]);
}

void unionSet(int par[], int x, int z) {
    int x_par = find(par, x);
    int z_par = find(par, z);
    
    if(x_par != z_par){
        par[x_par] = z_par;
    }
}

// METHOD 2: Using RANK and PATH COMPRESSION ----> optimized (Do not use this method on this gfg question)


int find(vector<int> &par, int x) {
    if(par[x] == x){
        return x;
    }
    
    return par[x] = find(par, par[x]);
}

void unionSet(vector<int> &par, int x, int z, vector<int> &rank) {
    int x_par = find(par, x);
    int z_par = find(par, z);
    
    if(x_par == z_par){
        return;
    }
    if(rank[x_par] < rank[z_par]){
        par[x_par] = z_par;
    }
    else if(rank[x_par] > rank[z_par]){
        par[z_par] = x_par;
    }
    else{
        rank[z_par] += 1;
    }
}
