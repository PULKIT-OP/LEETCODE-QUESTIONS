// Question Link: https://leetcode.com/problems/asteroid-collision/description/

// METHOD 1: 

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        int i = 0;
        
        while(i < n){
            // positive asteroid
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }
            // negative asteroid
            else if(asteroids[i] < 0){
                bool destroyed = false;
                while(!st.empty() && st.top() > 0){
                    // larger than previous positive
                    if(abs(asteroids[i]) > st.top()){
                        st.pop();
                    }
                    // equal to  previous positive
                    else if(abs(asteroids[i]) == st.top()){
                        destroyed = true;
                        st.pop();
                        break;
                    }
                    // smaller than previous positive this asteroid destroyed
                    else if(abs(asteroids[i]) < st.top()){
                        destroyed = true;
                        break;
                    }
                }
                if(!destroyed){
                    st.push(asteroids[i]);
                }
            }

            i++;
        }

        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
