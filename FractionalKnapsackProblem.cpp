// Q46 https://www.codingninjas.com/codestudio/problems/975286?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(nlog(n))
// Space: O(1)

#include<algorithm>
bool comp(pair<int, int> p1,pair<int, int>p2){
    double v1=(double) p1.second/(double)p1.first;
    double v2=(double) p2.second/(double)p2.first;
    return v2<v1;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w){
    sort(items.begin(),items.end(),comp);
//     for(auto i:items)
//         cout<<i.first<<" "<<i.second<<" "<<(double)i.second/i.first<<endl;
    double cw=0, v=0.0;
    for(int i=0;i<n;i++){
        if(cw+items[i].first<=w){
            cw+=items[i].first;
            v+=items[i].second;
//             cout<<items[i].second<<" ";
        }
        else{
            double remain=w-cw;
            v+=((double)items[i].second/(double)items[i].first)*(remain);
            break;
        }
    }
    return v;
}