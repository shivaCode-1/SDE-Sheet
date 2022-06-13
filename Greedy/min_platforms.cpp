int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,int>> hash;
    	for(int i=0;i<n;i++)
    	{
    	    hash.push_back({arr[i],dep[i]});
    	}
    	sort(hash.begin(),hash.end()); //sort based on arrival time
    	priority_queue<int,vector<int>,greater<int>> q; //minimum dep time always to be kept track of
    	q.push(hash[0].second);
    	int c = 1;
    	for(int i=1;i<n;i++)
    	{
    	    if(hash[i].first <= q.top()) //if current arrival time is less than any prev dep time
    	    {
    	        c++;
    	    }
    	    else
    	    {
    	        q.pop();
    	    }//a train leaves before next arrival, plaforms remain same.
    	    q.push(hash[i].second);
    	}
    	return c;
    }
