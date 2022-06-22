// Q32 https://leetcode.com/problems/linked-list-cycle/

// Slow fast approach
//Time: O(n)
//Space: O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode *s=head;
        ListNode *f=head;
        while(f->next&&f->next->next){
            s=s->next;
            f=f->next->next;
            if(s==f)
                return true;
        }
        return false;
    }
};


//Hashmap approach
//Time: O(n)
//Space: O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        unordered_map<ListNode*,int> m;
        ListNode *t=head;
        
        bool res=false;
        while(t->next){
            m[t]++;
            if(m[t]>1){
                res=true;
                break;
            }
            t=t->next;
        }
        return res;
    }
};