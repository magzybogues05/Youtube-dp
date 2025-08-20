class Solution {
  public:
  
    bool possible(int mid,vector<int>&arr,int k)
    {
        int n=arr.size();
        int c=1;
        int prev=arr[0];
        for(int i=1;i<n;i++)
        {
            if((arr[i]-prev)>=mid)
            {
                c++;
                prev=arr[i];
            }
            if(c==k)
            {
                return true;
            }
        }
        return false;
        
    }
    
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int l=0;
        int r=arr[n-1]-arr[0];
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(possible(mid,arr,k))
            {
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};
