class Solution {
  public:
    
    bool possible(int mid,vector<int>&arr,int k)
    {
        int val=0;
        int n=arr.size();
        int half=n/2;
        if(n%2==0)
        {
            val+=max(0,2*mid-arr[half]-arr[half-1]);
        }
        else{
            val+=max(0,mid-arr[half]);
        }
        for(int i=half+1;i<n;i++)
        {
            val+=max(0,mid-arr[i]);
        }
        return (val<=k);
    }
  
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int l=0;
        int r=arr[arr.size()-1]+k;
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
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