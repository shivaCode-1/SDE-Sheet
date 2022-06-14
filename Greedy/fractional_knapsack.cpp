static bool cmp(Item a,Item b)
    {
        double a1 = (double)a.value/(double)a.weight;
        double a2 = (double)b.value/(double)b.weight;
        return a1 > a2; 
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp); //sort by value per unit weight.
        double ans = 0;
        int i = 0;
        while(i<n && W > 0)
        {
            int wt = min(arr[i].weight,W); //take max weight that can bye taken
            ans+=(wt*((double)arr[i].value/(double)arr[i].weight));//calc that weights value
            W-=wt; //update remaining capacity.
            i++;
        }
        return ans;
        
    }
