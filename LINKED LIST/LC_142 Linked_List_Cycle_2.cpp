// Question Link: https://leetcode.com/problems/linked-list-cycle-ii/description/

// METHOD 1: Brute Force --> At each iteration check if you have seen this node if yes then that is the node where cycle starts otherwise store it as seen

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL){
            return NULL;
        }

        ListNode *temp = head;
        int i = 0;
        unordered_map<ListNode*, bool> mp;
        while(temp -> next != NULL){
            if(!mp.count(temp)){
                mp[temp] = true;
                temp = temp -> next;
            }
            else{
                return temp;
            }
        }

        return NULL;
    }
};


// METHOD 2: Using SLOW and FAST pointer --> 
// MATHS BEHIND THIS QUES ---> If you did not found cycle then easy, Return NULL
// Otherwise take pointer p at head and we already have slow at some node ---> from head to the node at which cycle starts take it as lenght L1 and from L1 to node at which slow is present take it as L2
// So the lenght from head to slow is L1 + L2. and if we have a cycle then fast must have cycled the loop multiple times, say n times. and in that cycle say K nodes are there 
// then total distance covered by fast ---> L1 + L2 + n*k. 
// and and and, as fast is moving twice the speed of slow so we can we ----> fast = 2 * (slow) ---> fast = 2 * (L1 + L2)
// Now equate both fast equation, you will get ---> L1 = nk - L2
// and nk - L2 is the distance that slow have to move to reach p and p have to move L1 distance from head to reach slow 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        bool loop = false;

      // First Check if we have cycle or not
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
          // if we have cycle then break 
            if(slow == fast){
                loop = true;
                break;
            }
        }
      // if you did not found cycle after while loop then return NULL 
        if(!loop){
            return NULL;
        }
      // otherwise take a pointer p at head
        ListNode *p = head;
        while(true){
          // if you get slow equals p then that node is your answer
            if(p == slow){
                return p;
            }
          // otherwise increment p and slow 
            p = p -> next;
            slow = slow -> next;
        }

      // Although you will never reach this line but return null 
        return NULL;
    }
};
