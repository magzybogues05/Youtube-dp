#define ll long long int
class Solution {
  public:
  
    bool possible(ll mid, vector<int>&arr, int k)
    {
        ll val=0;
        int n=arr.size();
        ll half=n/2;
        if(n%2==0)
        {
            val+=max(0LL,2*mid-arr[half]-arr[half-1]);
        }
        else{
            val+=max(0LL,mid-arr[half]);
        }
        for(int i=half+1;i<n;i++)
        {
            val+=max(0LL,mid-arr[i]);
        }
        return (val<=k);
    }
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
       sort(arr.begin(), arr.end());
       ll l=0;
       ll r=arr[arr.size()-1]+k;
       ll ans=0;
       while(l<=r)
       {
           ll mid=l+(r-l)/2;
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
