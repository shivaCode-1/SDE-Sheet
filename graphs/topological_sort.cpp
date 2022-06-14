//topological sort is that if u->v exists then u must come before v in topological sort.
//to perfrom this, run a normal dfs and after the dfs call is completed, insert the current node in a vector.
//reverse the final vector.
//this makes sure the all topological sorts are done before the final node is placed.
//this also makes sure that the current node is placed in the vector only when all of its depth in inside the vector.
void dfs(int i,vector<int> adj[],vector<int> &vis,vector<int> &res)
	{
	    if(vis[i]) return;
	    vis[i] = 1;
	    for(int s : adj[i])
	    {
	        if(!vis[s]) dfs(s,adj,vis,res);
	    }
	    res.push_back(i);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> res;
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,adj,vis,res);
	        }
	    }
	    reverse(res.begin(),res.end());
	    return res;
	}
