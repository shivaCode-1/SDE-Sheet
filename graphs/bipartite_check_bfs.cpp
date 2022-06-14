bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    //same logic, use bfs with parent and current node, and if at any point, parent and node
	    //color are same, return false;
	    vector<int> vis(V,-1);
	    queue<int> q;
	    for(int i=0;i<V;i++) //for every node, run bfs
	    {
	        if(vis[i]==-1) //if the node is not visited.
	        {
	            q.push(i); //push it in q
	            vis[i] = 1; //color it as 1.
	            while(!q.empty())
	            {
	                int curr = q.front(); 
	                //int p = q.front().second;
	                q.pop();
	                for(int s : adj[curr]) //now for every adjacent node,
	                {
	                    if(vis[s]==-1) //if the adj node is not coloured,
	                    {
	                        vis[s] = !vis[curr]; //color it exact opposite, and push
	                        q.push(s);
	                    }
	                    else if(vis[s]==vis[curr]) return false; //if its colored and same
	                    //as parent node, return false because its been colored by some other  node.
	                }
	            }
	        }
	    }
	    return true;
	}
//Also if cycle length is even, its bipartitre else not.
