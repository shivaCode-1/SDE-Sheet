 bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        queue<pair<int,int>> q; //pair to track the current and previous node.
        for(int i=0;i<V;i++)
        {
            if(vis[i]) continue;
            q.push({i,-1}); //for any starting node, prev is -1
            while(!q.empty())
            {
                int curr = q.front().first;
                int prev = q.front().second;
                vis[curr] = 1;
                q.pop();
                for(int s : adj[curr]) //if while traversing the current node, any visited node
    //encountered, and its not the parent then than means the graph contains cycle.
                {
                    if(!vis[s])
                    {
                        q.push({s,curr});
                    }
                    else if(s!=prev) return true;
                }
            }
        }
        return false;
    }
