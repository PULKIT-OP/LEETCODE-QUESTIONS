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



// METHOD 3: Using SIZE and PATH compression ----> Basic structure of code remains same 
// instead of increment of rank just when you find same rank we will be adding the size of children node to the parent node while union and when we find same size we do the same here as well
// Initialize size with 1 for each node.
// With this method you can find how many nodes are connected to each node
// Functioning and complexity of RANK-PATH compression and SIZE-PATH compression remains same 

    int find(int x, vector<int> &parent){
        if(parent[x] == x){
            return x;
        }
        
        return parent[x] = find(parent[x], parent);
    }
    
    void Union(int x, int y, vector<int> &parent, vector<int> &size){
        int x_par = find(x, parent);
        int y_par = find(y, parent);
        
        if(x_par == y_par){
            return;
        }
        if(size[x_par] > size[y_par]){
            parent[y_par] = x_par;
            size[x_par] += size[y_par];
        }
        else if(size[y_par] > size[x_par]){
            parent[x_par] = y_par;
            size[y_par] += size[x_par];
        }
        else{
            size[x_par]++;
            parent[y_par] = x_par;
            size[x_par] += size[y_par];
        }
    }
