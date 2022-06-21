// Q27
// https://leetcode.com/problems/merge-two-sorted-lists/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l2) return l1;
        if(!l1) return l2;
        if(l1->val>l2->val) swap(l1,l2);
        ListNode* r=l1;
        while(l1&&l2){
            ListNode* t=NULL;
            while(l1&& l1->val<=l2->val){
                t=l1;
                l1=l1->next;
            }
            t->next=l2;
            swap(l1,l2);

        }
        return r;
    }
};