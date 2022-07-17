// Q188 https://www.codingninjas.com/codestudio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=1

//Time: O(N*N)

struct Node{
  Node *links[26];
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node *node){
        links[ch-'a']=node;
    }
};

int countDistinctSubstrings(string &s){
    int cnt=0;
    Node* root= new Node();
    for(int i=0;i<s.size();i++){
        Node* node=root;
        for(int j=i;j<s.size();j++){
            if(!node->containsKey(s[j])){
                cnt++;
               node->put(s[j],new Node());
            }
            node=node->get(s[j]);
        }
    }
    return cnt+1; // +1 to add one empty subset
}