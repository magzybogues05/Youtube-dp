class Solution {
  public:
    
    int dp[46];
    int solve(int n)
    {
        if(n==1 || n==0)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans=solve(n-2)+solve(n-1);
        return dp[n]=ans;
    }
    
    int numberOfWays(int n) {
        // code here
        memset(dp,-1,sizeof dp);
        return solve(n);
    }
};