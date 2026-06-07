// Question Link: https://leetcode.com/problems/reverse-linked-list/

// METHOD 1:  Iterative method Using STACK ---> extra space O(N)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode *temp = head;
        stack<int> st;
        while(temp != NULL){
            st.push(temp -> val);
            temp = temp -> next;
        }

        temp = head;
        while(!st.empty()){
            temp -> val = st.top();
            st.pop();
            temp = temp -> next;
        }

        return head;
    }
};

// METHOD 2:  Without extra space -> recursion

class Solution {
public:
    ListNode *recur(ListNode *head){
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode *newHead = recur(head -> next);
        ListNode *nex = head -> next;
        nex -> next = head;
        head -> next = NULL;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {

        return recur(head);
    }
};


// METHOD 3: Without extra space  ->  Iterative method
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode *prev = NULL;
        ListNode *nex = head -> next;
        ListNode *curr = head;

        while(curr != NULL){
            nex = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nex;
        }

        return prev;
    }
};
