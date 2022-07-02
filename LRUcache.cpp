// Q83 https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    class node{
        public:
        int val;
        int key;
        node *prev;
        node *next;
        node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    int cap;
    unordered_map <int,node*> m;
    
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(node* newnode){
        node*t=head->next;
        newnode->next=t;
        newnode->prev=head;
        head->next=newnode;
        t->prev=newnode;
    }
    
    void deletenode(node* delnode){
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key_) {
        if(m.find(key_)!=m.end()){
            node* rnode=m[key_];
            int res=rnode->val;
            m.erase(key_);
            deletenode(rnode);
            addnode(rnode);
            m[key_]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_)!=m.end()){
            node *exn=m[key_];
            m.erase(key_);
            deletenode(exn);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key_,value));
        m[key_]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */