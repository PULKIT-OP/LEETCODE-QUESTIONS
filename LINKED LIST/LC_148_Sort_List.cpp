// Question Link: https://leetcode.com/problems/sort-list/


// METHOD 1: Brute Force ---> Using Extra Space

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode *temp = head;
        vector<int> vec;

        while(temp != NULL){
            vec.push_back(temp -> val);
            temp = temp -> next;
        }

        sort(vec.begin(), vec.end());

        temp = head;
        int i = 0;
        while(temp != NULL){
            temp -> val = vec[i];
            i++;
            temp = temp -> next;
        }

        return head;
    }
};


// METHOD 2: Using MergeSort Algorithm    ---->  Stack Space will be there as its a recursive solution

class Solution {
public:
    ListNode *merge(ListNode *list1, ListNode *list2){
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while(list1 != NULL && list2 != NULL){
            if(list1 -> val < list2 -> val){
                temp -> next = list1;
                temp = list1;
                list1 = list1 -> next;
            }
            else{
                temp -> next = list2;
                temp = list2;
                list2 = list2 -> next;
            }
        }

        if(list1){
            temp -> next = list1;
        }
        else{
            temp -> next = list2;
        }

        temp = dummy -> next;
        dummy -> next = NULL;
        delete(dummy);
        return temp;
    }
    ListNode *middleLL(ListNode *head){
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = slow -> next -> next;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }
    ListNode *ms(ListNode *head){
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode *mid = middleLL(head);

        ListNode *leftHead = head;
        ListNode *rightHead = mid -> next;

        mid -> next = NULL;

        leftHead = ms(leftHead);
        rightHead = ms(rightHead);

        return merge(leftHead, rightHead);
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        return ms(head);
    }
};
