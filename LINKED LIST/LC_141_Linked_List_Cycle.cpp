// Question Link: https://leetcode.com/problems/linked-list-cycle/description/

// METHOD 2: Using Map  ->  space O(N)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL){
            return false;
        }

        ListNode *slow = head;
        unordered_map<ListNode*, bool> visited;

        while(slow != NULL){
            if(visited[slow]){
                return true;
            }
            visited[slow] = true;
            slow = slow -> next;
        }

        return false;
    }
};

// METHOD 2: Using Slow fast pointer -> NO extra space

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL){
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        int count = 0;
        while(fast != NULL && fast -> next != NULL){
            if(count == 0){
                slow = slow -> next;
                fast = fast -> next -> next;
                count++;
                continue;
            }
            if(fast == slow){
                return true;
            }
            slow = slow -> next;
            fast = fast -> next -> next;
            count++;
        }

        return false;
    }
};
