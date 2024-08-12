bool detected(int node,vector<int> adj[], vector<bool> &vis, vector<bool> &path){
        vis[node] = 1;
        path[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++){
            if(path[adj[node][i]]){
                return true;
            }
            if(vis[adj[node][i]]) continue;
            if(detected(adj[node][i],adj,vis,path)){
                return true;
            }
        }
        
        path[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> path(V,0);
        vector<bool> vis(V,0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detected(i,adj,vis,path)){
                    return true;
                }
            }
        }
        
        return false;
        
    }