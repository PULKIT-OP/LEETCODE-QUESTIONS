// Question Link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

// METHOD 1: 

class Solution {
public:
  // Reversing the Linked List
    void reverseLL(ListNode *head){
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nex = NULL;

        while(curr != NULL){
            nex = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nex;
        }
        head = prev;
    }
// Finding the kth Node 
    ListNode *findKthNode(ListNode *head, int k){
        ListNode *temp = head;
        k--;
        while(temp != NULL && k > 0){
            k--;
            temp = temp -> next;
        }

        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        ListNode *prev = NULL;  // prev is NULL in starting

        while(temp != NULL){
            ListNode *tail = findKthNode(temp, k); // kth node from temp
          // if kth node doesnt exist then break the loop bcoz cant move further
            if(tail == NULL){
              // before breaking out of loop, check if prev pointer exist then join it to the list then break the loop
                if(prev){
                    prev -> next = temp;
                }
                break;
            }
          // store the next node which comes after current list of k nodes
            ListNode *nextNode = tail -> next;
            tail -> next = NULL;  // separate current list from main list temporarily
            reverseLL(temp);  // then reverse current list from temp to tail (k nodes)
            // after reversing temp came in end of current list and tail is at head of current list ---> pointer points at address not at nodes
            //    for exameple : 1 2 3 4 5 6 7    ---->     3 2 1 4 5 6
            //                   ^   ^                      ^   ^
            //                 temp tail                   tail temp
            // Now checking if temp is at head if yes it means this was the first group of k nodes --> place head to tail as now tail is in front after reversal
            if(temp == head){
                head = tail;
            }
            else{
                prev -> next = tail;  // if temp is not head means its not the first group then just join the previous group to this group ( tail is at front )
            }
            prev = temp;  // then update tail as well take it to last of this current group ( temp is at last )
            temp = nextNode;  // now update temp as well take it to next group which we stored as nextNode
        }

      // then at last return the head
        return head;
    }
};
