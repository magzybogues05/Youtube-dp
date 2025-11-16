class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int ans=0;
        int n=arr.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++)
        {
            dp[i]=max(dp[i],arr[i]);
            for(int j=i-1;j>=0;j--)
            {
                if(arr[i]>arr[j])
                { 
                    dp[i]=max(dp[i],arr[i]+dp[j]);
                    
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};