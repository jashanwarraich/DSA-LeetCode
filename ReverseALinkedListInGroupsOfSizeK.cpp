// Q33 https://leetcode.com/problems/reverse-nodes-in-k-group/
// O((N/k)*k)= O(n)


class Solution {
public:
    ListNode* reverseKGroup(ListNode* h, int k) {
        if(!h||k==1) return h;
        ListNode* dummy=new ListNode;
        dummy->next=h;
        ListNode *c=dummy, *p=dummy, *n=dummy;
        int cnt=0;
        while(c->next){
            cnt++;
            c=c->next;
        }
        
        while(cnt>=k){
            c=p->next;
            n=c->next;
            for(int i=1;i<k;i++){
                c->next=n->next;
                n->next=p->next;
                p->next=n;
                n=c->next;
            }
            p=c;
            cnt-=k;
        }
        return dummy->next;
    }
};
