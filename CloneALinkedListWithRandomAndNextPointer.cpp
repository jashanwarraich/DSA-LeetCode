// Q38 https://leetcode.com/problems/copy-list-with-random-pointer/


// Time: O(n)
// Space: O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *i=head, *f=head;
        while(i){
            f=i->next;
            Node *nn= new Node(i->val);
            i->next=nn;
            nn->next=f;
            i=f;
        }
        
        i=head;
        while(i){
            if(i->random) i->next->random=i->random->next;
            i=i->next->next;
        }
        
        i=head;
        Node *dh=new Node(0);
        Node *t=dh;
        while(i){
            f=i->next->next;
            t->next=i->next;
            i->next=f;
            t=t->next;
            i=f;
            
        }
        return dh->next;
    }
};