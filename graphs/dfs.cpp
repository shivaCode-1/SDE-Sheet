void dfs(int curr,vector<int> &vis,vector<int> &res,vector<int> adj[])
    {
        if(vis[curr]==1) return;
        vis[curr] = 1;
        res.push_back(curr);
        for(int i=0;i<adj[curr].size();i++)
        {
            if(vis[adj[curr][i]]) continue;
            dfs(adj[curr][i],vis,res,adj);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> res;
        vector<int> vis(V,0);
        dfs(0,vis,res,adj);
        return res;
        
    }
