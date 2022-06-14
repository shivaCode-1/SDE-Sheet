//Function to return list containing vertices in Topological order. 
//how does bfs work.
//see, indegree represents how many incoming edges a node have.
//So 0 indegree means in topological sort, we can put these nodes since no other node have
//a edge to them. so for u->v, there in no u for indegree 0 nodes.
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> in(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(int s : adj[i])
	        {
	            in[s]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(!in[i]) q.push(i);
	    }
	    vector<int> res;
	    while(!q.empty())
	    {
	        int curr = q.front();
	        res.push_back(curr);
	        q.pop();
	        for(int i : adj[curr])
	        {
	            in[i]--;
	            if(in[i]==0) q.push(i);
	        }
	    }
	    return res;
	}
//now the logic of subtarcting indegree is: if we are decreasing indegree and it becomes 0,
//that means, that current node have no node before it, or all other nodes are already placed
//in topo sort. So now we can place it inside topo sort.
