// Q158 https://leetcode.com/problems/course-schedule/submissions/

// Time: O(E+V)  //BFS
// Space: O(E+V)+O(V)+O(V)   

// IN Kahns algo using BFS it is only possible in DAG (Direcetd Acyclic graph)
// here we check it the topo sort contains all the nodes then it is not a cyclic graph hence returned true acc to the required output of the ques (need to return true if no cycle)
class Solution {

public:
    bool canFinish(int v, vector<vector<int>>& edge) {
        vector<int> adj[v]; //vector of arrays
        for(int i=0;i<edge.size();i++){
            adj[edge[i][0]].push_back(edge[i][1]);
    //         adj[edge[i][1]].push_back(edge[i][0]);
        }
        queue<int> q;
        vector<int> indeg(v,0);
        for(int i=0;i<v;i++){
            for(auto it: adj[i])
                indeg[it]++;
        }
        for(int i=0;i<v;i++){
            if(indeg[i]==0)
                q.push(i);
        }
        int cnt=0;
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            cnt++;
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        return cnt==v;
    }
};