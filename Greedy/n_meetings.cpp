static bool cmp(pair<int,int> &a,pair<int,int> &b)
    {
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({start[i],end[i]});
        }
        sort(arr.begin(),arr.end(),cmp);
        int c = 1;
        int e = arr[0].second;
        for(int i=1;i<n;i++)
        {
            if(arr[i].first > e)
            {
                e = arr[i].second;
                c++;
            }
        }
        return c;
    }
//select meetings which get over early so that next meetings can be accomodated.
