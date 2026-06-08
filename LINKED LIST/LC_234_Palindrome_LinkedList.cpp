// Question Link: https://leetcode.com/problems/palindrome-linked-list/description/

// METHOD 1: Using stack

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode *temp = head;

        while(temp != NULL){
            st.push(temp -> val);
            temp = temp -> next;
        }
        temp = head;
        while(!st.empty()){
            if(st.top() != temp -> val){
                return false;
            }
            st.pop();
            temp = temp -> next;
        }

        return true;
    }
};

// METHOD 2: Reversing the second half and comparing 

class Solution {
public:
  // Reversing the LinkedList with iterative method
    ListNode* reverseLL(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nex = NULL;

        while (curr != NULL) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head->next == NULL) {
            return true;
        }
        if (head->next->next == NULL) {
            if (head->val == head->next->val) {
                return true;
            }
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

      // Finding out Middle of Linked List
        while (fast != NULL && fast->next != NULL && fast -> next -> next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // if even --> 1 2 3 3 2 1
        //                 ^ --> now reverse the LL from slow -> next

        // if Odd --> 1 2 3 4 3 2 1
        //                  ^ ---> now reverse the LL from slow -> next
      
        ListNode* newHead = reverseLL(slow -> next);

        slow -> next = newHead;

        // 1 2 3 1 2 3
        slow = head;
        while (newHead != NULL) {
            if (slow->val != newHead->val) {
                return false;
            }
            slow = slow->next;
            newHead = newHead->next;
        }

      // only if it is asked to maintain the given data
        newHead = reverseLL(slow -> next);
        slow -> next = newHead;

        return true;
    }
};
