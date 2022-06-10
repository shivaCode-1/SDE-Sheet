int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        unordered_map<int,int> hash;
        int s = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            s+=arr[i];
            if(s==0)
            {
                ans = max(ans,i+1);
            }
            else
            {
                if(hash.find(s)!=hash.end())
                {
                    ans = max(ans,i-hash[s]);
                }
                else
                {
                    hash[s] = i;
                }
            }
        }
        return ans;
    }
