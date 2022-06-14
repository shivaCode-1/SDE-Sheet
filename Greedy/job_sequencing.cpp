static bool cmp(Job a,Job b)
    {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int max_slots = 0;
        for(int i=0;i<n;i++)
        {
            max_slots = max(max_slots,arr[i].dead); //find max slots.
        }
        //a job with deadline d, can be completed from 1 to d anytime.
        vector<int> slots(max_slots+1,-1); //create array of all available slots
        sort(arr,arr+n,cmp); //sort array by profit.
        vector<int> res(2,0);
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--) //now for every job check which slot is latest slot is available.
            {
                if(slots[j]==-1)
                {
                    slots[j] = i; //assign that slot,add profit, break and go to next job.
                    res[1]+=arr[i].profit;
                    res[0]++;
                    break;
                }
            }
        }
        return res;
        
    } 
