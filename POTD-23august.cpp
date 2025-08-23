class Solution {
  public:
  
    bool possible(int mid,vector<int>&arr,int k)
    {
        int n=arr.size();
        int c=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            
            if((sum+arr[i])>mid)
            {
                c++;
                sum=arr[i];
            }
            else{
                sum+=arr[i];
            }
            if(c==k)
            {
                return false;
            }
        }
        return true;
        
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k)
        {
            return -1;
        }
        int l=*max_element(arr.begin(),arr.end());
        int r=accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(possible(mid,arr,k))
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