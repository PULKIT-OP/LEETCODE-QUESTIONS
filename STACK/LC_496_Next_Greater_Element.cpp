// Question Link: https://leetcode.com/problems/next-greater-element-i/

// METHOD 1: Brute force method --> not optimises

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> result(n1, -1);
        unordered_map<int, int> mp;
        for(int i = 0; i < n2; i++){
            mp[nums2[i]] = i;
        }
        for(int i = 0; i < n1; i++){
            for(int j = mp[nums1[i]]; j < n2; j++){
                if(nums2[j] > nums1[i]){
                    result[i] = nums2[j];
                    break;
                }
            }
        }

        return result;
    }
};

// Using MONOTONIC STACK METHOD : 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> result(n2, -1);
        stack<int> st;
        unordered_map<int, int> mp;
        for(int i = 0; i < n2; i++){
            mp[nums2[i]] = i;
        }
        for(int i = n2-1; i >= 0; i--){
            if(st.empty()){
                result[i] = -1;
                st.push(nums2[i]);
            }
            else{
                if(st.top() > nums2[i]){
                    result[i] = st.top();
                    st.push(nums2[i]);
                }
                else{
                    while(!st.empty() && st.top() < nums2[i]){
                        st.pop();
                    }
                    if(!st.empty()){
                        result[i] = st.top();
                    }
                    st.push(nums2[i]);
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n1; i++){
            ans.push_back(result[mp[nums1[i]]]);
        }

        return ans;
    }
};
