// Question Link: https://leetcode.com/problems/rotate-list/

// METHOD 1:

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      // handle edge case
        if(head == NULL || head -> next == NULL){
            return head;
        }
        // Counting total number of nodes in list
        ListNode *temp = head;
        int count = 1;
        while(temp -> next != NULL){
            temp = temp -> next;
            count++;
        }

      // calculating number rotations we need to do 
      // if the k is multiple of length of length of list --> no need of rotation
      // for example : count = 5 and given K = 17 which means we need to do 17 rotation ? but if we go with our method then,
      // k becomes --> 2 which means we need to do only 2 rotation. why this happens?
      // If we try to rotate our list by 5 roation ---> then it becomes our original list again --> which means if we try to rotate list by multiple of 'count' rotation --> will get our list again
      // 17 ---> 5 + 5 + 5 + 2  ---> after 15 rotaion --> we get our list again --> then what is the need of doing that just do remaining 2 rotaion, and all set.
        k = k % count;
        if(k == 0){
            return head;
        }
        
        temp -> next = head;
        int res = abs(count - k);

        while(res > 0){
            temp = temp -> next;
            res--;
        }

      // at last just update the head and return the head
        head = temp -> next;
        temp -> next = NULL;

        return head;
    }
};
