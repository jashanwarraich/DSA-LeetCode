// Q186 https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

//Time: O(N)
struct Node{
    Node* links[26];
    int cntEndWith=0;
    int cntPrefix=0;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    int getEnd(){
        return cntEndWith;
    }
    int getPrefix(){
        return cntPrefix;
    }
};

class Trie{
    private:
    Node *root;
    public:

    Trie(){
        root=new Node();
        // Write your code here.
    }

    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
        // Write your code here.
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getPrefix();
    }

    void erase(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            node=node->get(word[i]);
            node->reducePrefix();
        }
        node->deleteEnd();
    }
};
