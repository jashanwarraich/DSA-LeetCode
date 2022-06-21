//Q 28

// O(n)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nh=new ListNode();
        nh->next=head;
        ListNode* f=nh;
        ListNode* s=nh;
        s->next=head;
        for(int i=0;i<n;i++){
            f=f->next;
        }
        
        while(f->next){
            s=s->next;
            f=f->next;
        }
        ListNode* del=s->next;
        s->next=s->next->next;
        delete del;
        return nh->next;
    }
    
};




//O(2n)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==0){
            return head;
        }
        ListNode* t=head;
        int c=0;
        while(t){
            c++;
            t=t->next;
        }

        if(c==n){
            return head->next;
        }
        int d=c-n;
        int i=0;
        ListNode* nh=head;
        ListNode* p=NULL;
        while(i<d){
            if(!p) p=nh;
            else p=p->next;
            if(nh->next)nh=nh->next;
            i++;
        }
        p->next=nh->next;
        return head;
    }
    
};