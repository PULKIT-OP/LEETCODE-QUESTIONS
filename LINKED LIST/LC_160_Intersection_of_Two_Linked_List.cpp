// Question Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

// METHOD 1: BruteForce method ---> store address of first list and then iterate over 2nd list if found the node then return

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode *, bool> mp;

        ListNode *temp = headA;
        while(temp != NULL){
            mp[temp] = true;
            temp = temp -> next;
        }

        temp = headB;
        while(temp != NULL){
            if(mp[temp]){
                return temp;
            }
            temp = temp -> next;
        }
        
        return NULL;
    }

};

// METHOD 2: Optimized method ----> NO extra space 

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        int A = 0;
        int B = 0;

      // Counting Number of nodes in both List
        while(tempA != NULL){
            A++;
            tempA = tempA -> next;
        }
        while(tempB != NULL){
            B++;
            tempB = tempB -> next;
        }

      // If ListA is longer
        if(A > B){
            tempA = headA;
            tempB = headB;

          // then take listA to the level of listB then find out the common node
            int result = A - B;
            for(int i = 0; i < result; i++){
                tempA = tempA -> next;
            }

            while(tempA != NULL && tempB != NULL){
                if(tempA == tempB){
                    return tempA;
                }
                tempA = tempA -> next;
                tempB = tempB -> next;
            }
        }
          // if listB is longer than listA
        else if(B > A){
            tempA = headA;
            tempB = headB;

          // then take listB to the level of listA then find out the common node
            int result = B - A;
            for(int i = 0; i < result; i++){
                tempB = tempB -> next;
            }

            while(tempA != NULL && tempB != NULL){
                if(tempA == tempB){
                    return tempA;
                }
                tempA = tempA -> next;
                tempB = tempB -> next;
            }
        }
          // if both lists are equal then just find out the common node
        else{
            tempA = headA;
            tempB = headB;

            while(tempA != NULL && tempB != NULL){
                if(tempA == tempB){
                    return tempA;
                }
                tempA = tempA -> next;
                tempB = tempB -> next;
            }
        }

      // other wise return NULL if no common node found
        return NULL;
    }
};

