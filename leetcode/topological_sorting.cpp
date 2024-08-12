void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
	    vis[node] = 1;
	    
	    for(int i=0; i<adj[node].size(); i++){
            if (!vis[adj[node][i]]) {
                dfs(adj[node][i], adj, vis, st);
            }
	    }
	    
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    vector<int> ans;
	    stack<int> st;
	    for(int i=0; i<V; i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}