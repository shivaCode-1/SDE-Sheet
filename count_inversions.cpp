long long merge(long long *arr,long long temp[],int s,int mid,int e)
{
    int i = s;
    int j = mid;
    int k = s;
    long long c = 0;
    while(i<=mid-1 && j<=e)
    {
        if(arr[i] > arr[j])
        {
            c+=(mid-i);
            temp[k++] = arr[j++];
        }
        else temp[k++] = arr[i++];
    }
    while(i<=mid-1) temp[k++] = arr[i++];
    while(j<=e) temp[k++] = arr[j++];
    for(int x = s;x<=e;x++)
    {
        arr[x] = temp[x];
    }
    return c;
}
long long solve(long long *arr,long long temp[],int s,int e)
{
    long long c = 0;
    if(s<e)
    {
        int mid = s + (e-s)/2;
        c+=solve(arr,temp,s,mid);
        c+=solve(arr,temp,mid+1,e);
        c+=merge(arr,temp,s,mid+1,e);
    }
    return c;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    long long temp[n];
    return solve(arr,temp,0,n-1);
    
}
