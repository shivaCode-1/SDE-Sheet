 vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> res;
        queue<int> q;
        q.push(0);
        vector<int> vis(V,0);
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            if(vis[curr]==1) continue;
            vis[curr]=1;
            res.push_back(curr);
            for(int i=0;i<adj[curr].size();i++)
            {
                if(vis[adj[curr][i]]) continue;
                q.push(adj[curr][i]);
            }
        }
        return res;
    }
