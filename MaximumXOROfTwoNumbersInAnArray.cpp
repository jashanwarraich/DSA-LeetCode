// Q190 https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

//Time: O(32*N)


struct Node{
  Node* links[2];
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    Node *get(int bit){
        return links[bit];
    }
    void put(int bit, Node* node){
        links[bit]=node;
    }
};

class Trie{
  private:
    Node * root;
    public:
    Trie(){
        root= new Node();
    }
    void insert(int num){
        Node *node=root;
        for(int i=31;i>=0;i--){
            int bit=num>>i&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    
    int getMax(int num){
        Node * node=root;
        int maxSum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit)){
                maxSum=maxSum|(1<<i); //understand it
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
            
        }
        return maxSum;
    }
    
};

class Solution {
public:
    int findMaximumXOR(vector<int>& a) {
        Trie trie;
        for(auto &it: a) trie.insert(it);
        int maxi=0;
        for(auto &it: a) maxi=max(maxi,trie.getMax(it));
        return maxi;

    }
};