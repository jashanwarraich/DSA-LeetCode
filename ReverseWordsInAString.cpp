// Q92 https://leetcode.com/problems/reverse-words-in-a-string/

// Time: O(n)
// Space: O(1)
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        string ans="";
        string t="";
        while(i<n){
            if(i!=0 && s[i-1]==' ' && s[i]==' '){ // To emit extra spaces at the end like after world in this test case  "     hello world     "
                i++;
                continue;
            }
            if(s[i]!=' ')
                t+=s[i];
            else{
                if(ans!="") ans=t+" "+ans;
                else ans=t;
                t="";
            }
            i++;
        }
        if(t!=""){
            if(ans!="") ans=t+" "+ans;
            else ans=t;
        }
        return ans;
    }
};



// Time: O(n)
// Space: O(n)
// Use a stack to push all the words in a stack
// Now, all the words of the string are present in the stack, but in reverse order
// Pop elements of the stack one by one and add them to our answer variable. Remember to add a space between the words as well. 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="TUF is great for interview preparation";
    cout<<"Before reversing words: "<<endl;
    cout<<s<<endl;
    s+=" ";
    stack<string> st;
    int i;
    string str="";
    for(i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            st.push(str);
            str="";
        }
        else str+=s[i];
    }
    string ans="";
    while(st.size()!=1)
    {
        ans+=st.top()+" ";
        st.pop();
    }
    ans+=st.top();// The last word should'nt have a space after it
    cout<<"After reversing words: "<<endl;
    cout<<ans;
    return 0;
}