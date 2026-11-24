// Question Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/


// METHOD 1: Using Brute force ----> thats not gonna work so dont waste time on it

// METHOD 2: Using Trie and BIT Manipulation

struct TrieNode {
    TrieNode* left = NULL; // zero
    TrieNode* right = NULL; // one
};
class Solution {
public:
    int n;
    void BuildTrie(TrieNode* root, int num){
        for(int i = 31; i >= 0; i--){
            int setbit = (num >> i) & 1;
            if(setbit){
                if(root -> right == NULL){
                    root -> right = new TrieNode();
                }
                root = root -> right;
            }
            else{
                if(root -> left == NULL){
                    root -> left = new TrieNode();
                }
                root = root -> left;
            }
        }
    }

    int solve(TrieNode* root, int num){
        int result = 0;
        for(int i = 31; i >= 0; i--){
            int setBit = (num >> i) & 1;
            if(!setBit){
                if(root -> right){
                    root = root -> right;
                    int bit = 1 << i;
                    result = result | bit;
                }
                else if(root -> left){
                    root = root -> left;
                }
                else{
                    break;
                }
            }
            else{
                if(root -> left){
                    root = root -> left;
                    int bit = 1 << i;
                    result = result | bit;
                }
                else if(root -> right){
                    root = root -> right;
                }
                else{
                    break;
                }
            }
        }

        return result;
    }
    int findMaximumXOR(vector<int>& nums) {
        n = nums.size();

        TrieNode* root = new TrieNode();

        for(int i = 0; i < n; i++){
            BuildTrie(root, nums[i]);
        }

        int result = 0;
        for(int i = 0; i < n; i++){
            int xorVal = solve(root, nums[i]);
            result = max(result, xorVal);
        }

        return result;
    }
};
