// Question Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

// METHOD 1: Multiple iteration 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head -> next == NULL){
            return NULL;
        }

        int cnt = 0;
        ListNode *temp = head;

        while(temp != NULL){
            cnt++;
            temp = temp -> next;
        }
        if(cnt == n){
            temp = head;
            head = head -> next;
            temp -> next = NULL;
            delete(temp);
            return head;
        }

        cnt = cnt - n;
        temp = head;

        while(temp != NULL){
            cnt--;
            if(cnt == 0){
                break;
            }
            temp = temp -> next;
        }

        ListNode *del = temp -> next;
        temp -> next = temp -> next -> next;
        del -> next = NULL;
        delete(del);

        return head;
    }
};

// METHOD 2: Reverse the list then reach to destination and free the node 

class Solution {
public:
    ListNode *reverseLL(ListNode *head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nex = NULL;

        while(curr != NULL){
            nex = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nex;
        }

        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // reverse the list
        if(head == NULL || head -> next == NULL){
            return NULL;
        }
        if(n == 1){
            ListNode *temp = head;
            while(temp -> next != NULL && temp -> next -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = NULL;
            return head;
        }
        ListNode *newHead = reverseLL(head);
        ListNode *temp = newHead;
        int target = 1;
        while(temp != NULL && target < n-1){
            temp = temp -> next;
            target++;
        }
        ListNode *nex = temp -> next;
        temp -> next = temp -> next -> next;
        nex -> next = NULL;

        head = reverseLL(newHead);

        return head;
    }
};

// METHOD 3: Most Optimized Method 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head -> next == NULL){
            return NULL;
        }

      // take fast n steps forward 
        ListNode *fast = head;
        ListNode *slow = head;
        for(int i = 0; i < n; i++){
            fast = fast -> next;
        }

      // If fast reached null it means n is first node so you gotta delete that one and return head -> next
        if(fast == NULL){
            slow = head -> next;
            head -> next = NULL;
            delete(head);
            return slow;
        }

      // If fast hasnt reached null then you move both fast and slow pointer one step forward at each iteration
        while(fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }

      // This will take slow pointer just before the target node and now just delete that target node and return the head
        ListNode *del = slow -> next;
        if(slow -> next){
            slow -> next = slow -> next -> next;
            del -> next = NULL;
        }
        delete(del);

        return head;
    }
};
