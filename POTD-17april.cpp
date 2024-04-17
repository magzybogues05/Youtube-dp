class Solution{
    public:
    int merge(int l,int mid,int r,int arr[])
    {
        int i=l;
        int j=mid+1;
        int k=0;
        int ans=0;
        vector<int>temp(r-l+1,0);
        while(i<=mid && j<=r)
        {
            if(arr[i]<=arr[j])
            {
                temp[k]=arr[i];
                i++;
                k++;
            }
            else{
                ans+=(mid-i+1);
                temp[k]=arr[j];
                j++;
                k++;
            }
        }
        while(i<=mid)
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
        while(j<=r)
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
        for(int i=l;i<=r;i++)
        {
            arr[i]=temp[i-l];
        }
        return ans;
    }
    int mergesort(int l,int r,int arr[])
    {
        if(l>=r)
        {
            return 0;
        }
        int mid=l+(r-l)/2;
        int left=mergesort(l,mid,arr);
        int right=mergesort(mid+1,r,arr);
        int curr=merge(l,mid,r,arr);
        return left+right+curr;
    }
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here 
        for(int i=0;i<n;i++)
        {
            arr[i]*=i;
        }
        return mergesort(0,n-1,arr);
    }
};