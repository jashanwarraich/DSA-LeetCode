// Q25 https://leetcode.com/problems/reverse-linked-list/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *nh=NULL;
        while(head){
            ListNode* next=head->next;
            head->next=nh;
            nh=head;
            head=next;
        }
        return nh;
    }
};