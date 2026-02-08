// Question Link: https://leetcode.com/problems/merge-k-sorted-lists/description/

// METHOD 1: Linear Method iteration from 0 to n-1 and merging all the lists

class Solution {
public:
    ListNode *merge(ListNode *l1, ListNode *l2){
      // if l1 is NULL return l2
        if(l1 == NULL){
            return l2;
        }
      // if l2 is NULL return l1
        if(l2 == NULL){
            return l1;
        }

      // otherwise if you get value of l1 is smaller than l2 ---> means l1 will come before l2 or remaining list
        if(l1 -> val <= l2 -> val){
          // so now get l1 -> next from remaining list from recursion
            l1 -> next = merge(l1 -> next, l2);
            return l1;
        }
        else{
          // otherwise get l2 -> next from remaining list from recursion
            l2 -> next = merge(l1, l2 -> next);
            return l2;
        }
        return NULL;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
      // if list is empty --> no sorting return null
        if(n == 0){
            return NULL;
        }
      // if list has only 1 list ---> return that list, as that will be sorted 
        if(n == 1){
            return lists[0];
        }

      // make a result pointer to store merged list
        ListNode *result = NULL;
        for(int i = 0; i < n; i++){
          // now merge lists[i] in results
            result = merge(lists[i], result);
        }

      // at last return results
        return result;
    }
};


// METHOD 2: Divide and Concour Method ---> Just Like MERGE SORT

class Solution {
public:
    int n;

// Here merge logic remains same 
    ListNode *merge(ListNode *l1, ListNode *l2){
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }

        if(l1 -> val <= l2 -> val){
            l1 -> next = merge(l1 -> next, l2);
            return l1;
        }
        else{
            l2 -> next = merge(l1, l2 -> next);
            return l2;
        }
        
        return NULL;
    }
    ListNode *solve(int s, int e, vector<ListNode*> &lists){
        int mid = s + (e - s)/2;

      // base case 1: if s and e are at the same position ---> then return that list 
        if(e == s){
            return lists[e];
        }
      // or if s > e then return null as that is not possible
        if(s > e){
            return NULL;
        }
      // Now get the solve for left half and right half separately
        ListNode *left = solve(s, mid, lists);
        ListNode *right = solve(mid+1, e, lists);

      // at last merge the sorted left and right half
        return merge(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        n = lists.size();

      // handling the case if list is empty or only has 1 list
        if(n == 0){
            return NULL;
        }
        if(n == 1){
            return lists[0];
        }
      
        int s = 0; 
        int e = n-1;

      // solve function will get you the head of sorted list
        return solve(s, e, lists);
    }
};
