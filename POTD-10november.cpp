class Solution {
  public:
  
    int maxProfit(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(3,0));
        dp[0][0]=-1*arr[0];
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][2]-arr[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+arr[i]);
            dp[i][2]=max(dp[i-1][2],dp[i-1][1]);
        }
        return max(dp[n-1][1],dp[n-1][2]);
    }
};