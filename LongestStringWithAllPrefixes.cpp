// Q187 https://www.codingninjas.com/codestudio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=1

//Time: O(N* len)




struct Node{
    Node *links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node= root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool CheckIfAllPrefixExists(string word){
        Node *node=root;
        bool flag=true;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                flag=flag & node->isEnd();
            }
            else{
                return false;
            }
        }
        return flag;
    }
};

string completeString(int n, vector<string> &a){
    Trie* obj=new Trie();
    for(auto it: a) obj->insert(it);
    string ans="";
    for(auto word: a){
        if(obj->CheckIfAllPrefixExists(word)){
            if(word.length()>ans.length()){
                ans=word;
            }
            else if(word.length()==ans.length()&&word<ans){
                ans=word;
            }
        }
        
    }
    if(ans=="") return "None";
    return ans;
}