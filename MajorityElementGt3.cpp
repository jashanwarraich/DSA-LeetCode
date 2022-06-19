// https://leetcode.com/problems/majority-element-ii/submissions/


// O(n)

class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int c1=0,c2=0,num1=-1,num2=-1;
        int rf=arr.size()/3;
//         num= candidate, c=count
        vector <int> v;
        for (auto i : arr){
            //take care of the sequence of the conditions num==i to be performed before c==0
            if(num1==i){
                c1++;
            }
            else if(num2==i){
                c2++;
            }
            else if(c1==0){
                num1=i;
                c1=1;

            }
            else if(c2==0){
                num2=i;
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        // cout<<num1<<num2<<rf;
        int f1=0, f2=0;
        for(auto i:arr){
            if(i==num1) f1++;
            else if(i==num2) f2++;
        }
        if(f1>rf) v.push_back(num1);
        if(f2>rf) v.push_back(num2);

        return v;
    }
};

// O(nLogn)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> arr=nums;     
        int n=arr.size();
        unordered_map<int,int> h;
        for(int i=0;i<n;i++){
            h[arr[i]]++;
        }

        vector <int> v;
        for (auto i : h)
            if(i.second>n/3)
                v.push_back(i.first);
        
        return v;
    }
};

