// Question Link: https://leetcode.com/problems/sliding-puzzle/description/


// METHOD 1: Using BFS
// represent each state in string and do each operation on string not on actual board
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int, vector<int>> mp = {
            {0, {1, 3}},
            {1, {0, 2, 4}},
            {2, {1, 5}},
            {3, {0, 4}},
            {4, {1, 3, 5}},
            {5, {2, 4}}
        };  

        string start = "";
        string target = "123450";
        int src_idx;  // where is zero?
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                start += (to_string(board[i][j]));
                if(board[i][j] == 0){
                    src_idx = i * 3 + j;
                }
            }
        }

        unordered_map<string, bool> visited;
        queue<pair<int, string>> q;
        q.push({src_idx, start});
        visited[start] = true;

      // Normal BFS Logic 
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                auto temp = q.front();
                q.pop();
                int idx = temp.first;
                string state = temp.second;

                if(state == target){
                    return steps;
                }

                for(auto neigh : mp[idx]){
                    string neww = state;
                    swap(neww[idx], neww[neigh]);
                    if(visited[neww] == false){
                        q.push({neigh, neww});
                        visited[neww] = true;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
