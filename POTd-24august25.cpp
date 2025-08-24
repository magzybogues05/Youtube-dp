class Solution {
  public:
    
    bool possible(int mid,vector<int>&arr,int k,int m)
    {
        int count=0;
        int b=0;
        for(auto it:arr)
        {
            if(it<=mid)
            {
                count++;
            }
            else{
                b+=count/k;
                count=0;
            }
        }
        b+=(count/k);
        return (b>=m);
    }
  
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int l=*min_element(arr.begin(),arr.end());
        int r=*max_element(arr.begin(),arr.end());
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(possible(mid,arr,k,m))
            {
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};