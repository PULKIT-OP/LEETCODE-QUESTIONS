// Question Link: https://leetcode.com/problems/delete-node-in-a-linked-list/

// METHOD 1: Iteration + Swapping in the Linked List

class Solution {
public:
    void deleteNode(ListNode* node) {
      // marking curr
        ListNode *curr = node;
      // marking prev as null
        ListNode *prev = NULL;

      // iterating on List until i reach at the end
        while(curr -> next != NULL){
          // marking next node
            ListNode *nex = curr -> next;
          // storing value of current node in temp_val
            int temp_val = curr -> val;
          // Swapping values of curr node and next node
            curr -> val = nex -> val;
            nex -> val = temp_val;
          // marking prev as current 
            prev = curr;
          // changing current in next
            curr = nex;
        }

      // at last curr will be on last node with value "node" and prev will be just before that you just have to disconnect prev from current

        prev -> next = NULL;

    }
};
