// Q88 https://leetcode.com/problems/rotting-oranges/

// Time: O(n*m)*4
// Space: O(n*m)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int m=a.size(), n=a[0].size(),d=0,tot=0,cnt=0;
        queue<pair<int,int>> rot;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]!=0) tot++;
                if(a[i][j]==2) rot.push({i,j});
            }
        }
        int dx[]={0,1,0,-1}; //URBL
        int dy[]={1,0,-1,0};
        while(!rot.empty()){
            int k=rot.size();
            cnt+=k;
            while(k--){
                int x=rot.front().first, y=rot.front().second;
                rot.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i], ny=y+dy[i];
                    if(nx<0||ny<0||nx>=m||ny>=n||a[nx][ny]!=1)continue;
                    a[nx][ny]=2;
                    rot.push({nx,ny});
                }
                
            }
            if(!rot.empty())d++;
        }
        return tot==cnt?d:-1;
    }
};