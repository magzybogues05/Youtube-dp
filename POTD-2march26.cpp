#define ll long long int
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
       int n=arr.size();
       int ans=0;
       int l=0;
       int r=n-1;
       int lmax=0;
       int rmax=0;
       while(l<=r)
       {
           lmax=max(lmax,arr[l]);
           rmax=max(rmax,arr[r]);
           
           if(lmax<rmax)
           {
               ans+=lmax-arr[l];
               l++;
           }
           else{
               ans+=rmax-arr[r];
               r--;
           }
       }
       return ans;
    }
};