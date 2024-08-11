class Solution {
public:
    bool check(int node,vector<vector<int>>& graph,vector<int> &vis, int color,queue<int> &q){
        q.push(node);
        vis[node]=color;

        while(!q.empty()){
            int ele = q.front();
            q.pop();

            for(auto i : graph[ele]){
                if(vis[i]==-1){
                    vis[i] = !vis[ele]; //give opp color of parent if visiting first time
                    q.push(i);
                }
                else if(vis[i]==vis[ele]){ //if already visited and having same color as that of parent
                    return false;
                }
            }
        }
        
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        //take 2 colors 0 and 1
        int n = graph.size();
        vector<int> vis(n,-1);
        queue<int> q;
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(check(i,graph,vis,0,q)==false){
                    return false;
                }
            }
        }
        return true;
    }
};