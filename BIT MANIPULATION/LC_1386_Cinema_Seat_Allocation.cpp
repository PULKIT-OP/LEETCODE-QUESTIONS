// Question Link: https://leetcode.com/problems/cinema-seat-allocation


// METHOD 1: Using Hashmap and iterations --> takes more time and space 

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int reserved_m = reservedSeats.size();

        unordered_map<int, unordered_set<int>> mp;

        for(int i = 0; i < reserved_m; i++){
            int x = reservedSeats[i][0];
            int y = reservedSeats[i][1];
            mp[x].insert(y);
        }

        int emptyRows = n - mp.size();
        int total_Group = emptyRows*2;

        vector<vector<int>> groups = {{2, 3, 4, 5}, {4, 5, 6, 7}, {6, 7, 8, 9}};

        for(auto &e : mp){
            // left block
            bool left = true;
            for(int seat = 2; seat <= 5; seat++){
                if(e.second.count(seat)){
                    left = false;
                    break;
                }
            }
            // middle block
            bool middle = true;
            for(int seat = 4; seat <= 7; seat++){
                if(e.second.count(seat)){
                    middle = false;
                    break;
                }
            }
            // right block
            bool right = true;
            for(int seat = 6; seat <= 9; seat++){
                if(e.second.count(seat)){
                    right = false;
                    break;
                }
            }

            if(left == true && right == true){
                total_Group += 2;
            }
            else if(left || middle || right){
                total_Group ++;
            }
        }

        return total_Group;
    }
};


// METHOD 2: Using Bitmask ---> takes less space and time
// logic behind this is --> instead of storing set of each reserved row  -->  we can use bits ---> set bits means --> reserved seat
// we will make setBits for all three Groups as well
// and if we take '&' of reserved seat and all three group --> if we get zero ---> it means that seat for that particular group is available
// if its not zero means --> some seats are occupied

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int reserved_m = reservedSeats.size();

        unordered_map<int, int> mp;

        for(int i = 0; i < reserved_m; i++){
            int x = reservedSeats[i][0];
            int y = reservedSeats[i][1];
            mp[x] = mp[x] | (1 << y);
        }

        int emptyRows = n - mp.size();
        int total_Group = emptyRows*2;

        int maskA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int maskB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int maskC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for(auto &[row, bookedSeatsMask] : mp){
            bool GroupA = (bookedSeatsMask & maskA) == 0;
            bool GroupB = (bookedSeatsMask & maskB) == 0;
            bool GroupC = (bookedSeatsMask & maskC) == 0;

            if(GroupA == true && GroupC == true){
                total_Group += 2;
            }
            else if(GroupA || GroupB || GroupC){
                total_Group++;
            }
        }

        return total_Group;
    }
};
