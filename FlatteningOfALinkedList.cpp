// Q36 https://www.codingninjas.com/codestudio/problems/1112655?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

//Time: O(total number of nodes)

// Using old question of MergeTwoSortedLinkedList  (Q27 https://leetcode.com/problems/merge-two-sorted-lists/)
Node* mergeTwoLists(Node* l1,Node* l2){
        if(!l2) return l1;
        if(!l1) return l2;
        if(l1->data>l2->data) swap(l1,l2);
        Node* r=l1;
        while(l1&&l2){
            Node* t=NULL;
            while(l1 && l1->data<=l2->data){
                t=l1;
                l1=l1->child;
            }
            t->child=l2;
            swap(l1,l2);

        }
        return r;
}


Node* flattenLinkedList(Node* head){
    if(!head||!head->next) return head;
    head->next=flattenLinkedList(head->next);
    head=mergeTwoLists(head,head->next);
    return head;
}



// Using different function for merging sorted LL
Node* mergeTwoLists(Node* l1,Node* l2){
    Node* t= new Node(0);
    Node* res=t;
    while(l1&&l2){
        if(l1->data<=l2->data){
            t->child=l1;
            l1=l1->child;
        }
        else{
            t->child=l2;
            l2=l2->child;
        }
        t=t->child;
    }
    if(l1)t->child=l1;
    else t->child=l2;
    
    return res->child;
}


Node* flattenLinkedList(Node* head){
    if(!head||!head->next) return head;
    head->next=flattenLinkedList(head->next);
    head=mergeTwoLists(head,head->next);
    return head;
}
