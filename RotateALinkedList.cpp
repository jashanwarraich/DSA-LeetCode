// Q37 https://leetcode.com/problems/rotate-list/description/

//Best Approach
// Time: o(n)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head|| !head->next||k<=0) return head;
        int n=1;
        ListNode *t=head;
        while(t->next){
            t=t->next;
            n++;
        }
        t->next=head;
        k=k%n;
        k=n-k;
        while(k--)t=t->next;
        head=t->next;
        t->next=NULL;
        return head;
    }
};





//Time: O(n)
// rev(0-n)
// rev(0-k)
// rev(k-n)
class Solution {
public:
    ListNode* rev (ListNode* h, int rot){
        ListNode *nh=NULL;
        while(rot--){
            ListNode* n=h->next;
            h->next=nh;
            nh=h;
            h=n;
        }
        return nh;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head|| !head->next||k<=0) return head;
        int n=0;
        ListNode *t=head;
        while(t){
            t=t->next;
            n++;
        }
        k=k%n;
        if(k<=0||k==n) return head;
        head=rev(head,n);
        t=head;
        int i=0;
        while(i<k){
            t=t->next;
            i++;
        }
        head=rev(head,k);
        t=rev(t,n-k);
        ListNode *t2=head;
        while(t2->next){
            t2=t2->next;
        }
        t2->next=t;
        return head;
    }
};