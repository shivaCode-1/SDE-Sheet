//always remember the concept of parent, because a revisited node can be there if its the parent of the current node.
bool dfs(int n,int p,vector<int> adj[],vector<int> &vis)
    {
        vis[n] = 1;
        for(int i : adj[n])
        {
            if(!vis[i])
            {
                if(dfs(i,n,adj,vis)) return true;
            }
            else if(i!=p) 
            return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V+1,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,adj,vis)) return true;
            }
        }
        return false;
    }
