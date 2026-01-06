class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int ans=0;
        int xorr=0;
        for(int i=0;i<k-1;i++)
        {
            xorr^=arr[i];
        }
        for(int i=k-1;i<n;i++)
        {
            xorr^=arr[i];
            ans=max(ans,xorr);
            xorr^=arr[i-k+1];
        }
        return ans;
    }
};