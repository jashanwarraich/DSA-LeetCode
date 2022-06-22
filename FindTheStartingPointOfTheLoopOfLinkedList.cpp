// Q35 https://leetcode.com/problems/linked-list-cycle-ii/

// Slow fast approach
//Time: O(n)
//Space: O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *s=head;
        ListNode *f=head;
        ListNode *t=head;
        while(f->next&&f->next->next){
            s=s->next;
            f=f->next->next;
            if(s==f){               //cycle detected
                while(s!=t){
                    s=s->next;
                    t=t->next;
                }
                return s;
            }
        }
        return NULL;
    }
};



//Hashmap approach
//Time: O(n)
//Space: O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        unordered_map<ListNode*,int> m;
        ListNode *t=head;
        while(t->next){
            m[t]++;
            if(m[t]>1){
                return t;
                break;
            }
            t=t->next;
        }
        return NULL;
    }
};