// Question Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

// METHOD 1: Using brute force --> first count total nodes then calculate middle node then iterate till middle node then delete it from list

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *temp = head;

      // calculete total nodes
        int n = 0;
        while(temp != NULL){
            n++;
            temp = temp -> next;
        }

      // if nodes are two then return first node
        if(n == 2){
            head -> next = NULL;
            return head;
        }
      // if only 1 node is present then return null
        if(n == 1){
            return NULL;
        }

      // calculate middle node
        int mid = n/2;

        temp = head;
        ListNode* prev = NULL;

        int i = 0;

      // iterate till middle node
        while(i != mid){
            i++;
            prev = temp;
            temp = temp -> next;
        }

      // remove middle node from list
        prev -> next = temp -> next;
        temp -> next = NULL;

      // return head;
        return head;

    }
};

// METHOD 2: Iterate only one time with slow fast method then delete middle node

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
      // if only 1 node in list then delete it and return null
        if(head -> next == NULL){
            return NULL;
        }
        ListNode *prev = NULL;
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast != NULL && fast -> next != NULL){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        prev -> next = slow -> next;
        slow -> next = NULL;
        delete slow;

        return head;
    }
};
