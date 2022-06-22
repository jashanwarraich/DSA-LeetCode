//Q31 https://leetcode.com/problems/intersection-of-two-linked-lists/

// O N*M 

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        ListNode * t1=new ListNode;
        ListNode * t2=new ListNode;
        t1->next=A;
        t2->next=B;
        ListNode * r=NULL;
        while(t1->next){
            t2=B;
            while(t2->next && !r){
                if(t1==t2){
                    r=t1;
                    break;
                }
                // cout<<t2->val<<" ";
                t2=t2->next;
            }
            t1=t1->next;
        }
        if(!r && t1==t2) return t1; //A=[1] B=[1] for this input
        
        return r;
    }
};

// Time: O(m+n) 
// Space: O(n) 
// store all noded of L1 in the hashtable(addresses) 
// and then store the same for L1
// if the node is already present in hashtable 
// return it


// Time: O(n)
// Space: O(1)
// Find d= length(l1)-length(l2);
// travel d nodes of the longer LL 
// after that travel for LL one node at a time 
// whereever they meet return it

//More Optimised approach
// Time: O(n)
// Space: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        if(!A||!B) return NULL;
        ListNode * a=A;
        ListNode * b=B;
        while(a!=b){
            a=a!=NULL?a->next:B;
            b=b!=NULL?b->next:A;
        }
        return a;
    }
};